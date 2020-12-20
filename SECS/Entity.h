#pragma once
#include <cstdint>
#include <functional>

//
// index_bit_mask = 0x 00000000 11111111 11111111 11111111
//
constexpr uint32_t index_bit_count = 24;
constexpr uint32_t index_bit_mask = (1 << index_bit_count) - 1;

//                  
// batch_bit_mask = 0x 11111111 00000000 00000000 00000000
//
constexpr uint32_t batch_bit_count = 8;
constexpr uint32_t batch_bit_mask = ((1 << batch_bit_count) - 1) << 24;

namespace secs
{
	struct _declspec(dllexport) Entity
	{ 
	private:
		uint32_t m_Id;

	public:
		Entity() : m_Id(0) {}
		Entity(uint32_t id) : m_Id(id) {}
		Entity(uint32_t id, uint8_t batch) : m_Id(id | (batch << index_bit_count)) {}

		inline uint32_t Index() const { return (m_Id & index_bit_mask); }
		inline uint32_t Batch() const { return ((m_Id & batch_bit_mask) >> index_bit_count); }

		bool operator==(const Entity& rs) const
		{
			return (Index() == rs.Index() && Batch() == rs.Batch());
		}
	};
}

namespace std
{
	template<> 
	struct hash<secs::Entity>
	{
		std::size_t operator()(const secs::Entity& e) const noexcept
		{
			std::size_t h1 = std::hash<uint32_t>{}(e.Index());
			std::size_t h2 = std::hash<uint32_t>{}(e.Batch());
			return h1 ^ (h2 << 1); 
		}
	};
}
