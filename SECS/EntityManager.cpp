#include "EntityManager.h"



secs::EntityManager::EntityManager()
{
}


secs::EntityManager::~EntityManager()
{
}

Entity& secs::EntityManager::createEntity()
{
	while (m_entityPool[m_nextEntity]) // while entity is alive
	{
		m_nextEntity++;
	}
	m_entityPool[m_nextEntity] = true;

	return m_nextEntity;
}

bool secs::EntityManager::isAlive(Entity e)
{
	return m_entityPool[e];
}
