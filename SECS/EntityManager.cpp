#include "EntityManager.h"

//
// Minimum number of destroyed entities before recycling an id
//
constexpr uint16_t min_free_indices = 1024;

namespace secs
{
	secs::EntityManager::EntityManager()
	{
	}


	secs::EntityManager::~EntityManager()
	{
	}

	const Entity & secs::EntityManager::create()
	{
		uint32_t id;
		if (m_FreeIndices.size() > 1024)
		{
			id = m_FreeIndices.front();
			m_FreeIndices.pop_front();
		}
		else
		{
			m_Batch.push_back(0);
			id = m_Batch.size() - 1;
		}

		m_Entities.emplace_back(id, m_Batch[id]);
		return m_Entities.back();
	}

	bool secs::EntityManager::IsAlive(const Entity& e)
	{
		return m_Batch[e.Index()] == e.Batch();
	}

	void EntityManager::Destroy(const Entity & e)
	{
		const uint32_t id = e.Index();
		m_Batch[id]++;
		m_FreeIndices.push_back(id);
	}

}