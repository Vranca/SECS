#pragma once
#include "Entity.h"
#include "ISystem.h"
#include "EntityManager.h"

#include <vector>

namespace secs
{
	class Scene
	{
	public:
		Scene();
		~Scene();

		Entity& createEntity();

		template<typename Component>
		Component addComponent(Entity e, Component arg)
		{


			return arg;
		}

	private:
		EntityManager m_entityManager;
	};
	
}

