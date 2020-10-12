#pragma once

#include "Entity.h"
#include <vector>

namespace secs
{
	class EntityManager
	{
	public:
		EntityManager();
		~EntityManager();

		Entity& createEntity();
		bool isAlive(Entity e);
	private:
		Entity m_nextEntity = 0;
		std::vector<bool> m_entityPool; // Default initiallized to false
	};
}

