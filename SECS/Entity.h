#pragma once
#include <cstdint>

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
	struct Entity
	{ 
	private:
		uint32_t m_Id;

	public:
		Entity(uint32_t id) : m_Id(id) {}
		Entity(uint32_t id, uint8_t batch) : m_Id(id & (batch << index_bit_count)) {}

		inline uint32_t Index() const { return (m_Id & index_bit_mask); }
		inline uint32_t Batch() const { return ((m_Id & batch_bit_mask) >> index_bit_count); }
	};
}
