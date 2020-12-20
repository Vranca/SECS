#pragma once

#include "Entity.h"
#include <vector>
#include <deque>

namespace secs
{
	class _declspec(dllexport) EntityManager
	{
	public:
		EntityManager();
		~EntityManager();
		const Entity& create();
		bool IsAlive(const Entity& e);
		void Destroy(const Entity& e);

	private:
		std::vector<uint8_t> m_Batch;
		std::deque<uint32_t> m_FreeIndices;
		std::vector<Entity> m_Entities;
	};
}

