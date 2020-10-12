#include "Scene.h"



secs::Scene::Scene()
{
}


secs::Scene::~Scene()
{
}

Entity& secs::Scene::createEntity()
{
	return m_entityManager.createEntity();
}

