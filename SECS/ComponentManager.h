#pragma once
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <stdint.h>
#include "Entity.h"

namespace secs
{
	template <typename Component>
	class _declspec(dllexport) ComponentManager
	{
	private:
		std::vector<Component> m_Components;
		std::unordered_map<Entity, uint32_t> m_IndicesMap;
		std::unordered_map<uint32_t, Entity> m_EntityMap;

	public:
		ComponentManager() {};
		~ComponentManager() {};

		//template<typename Component>
		bool  AddComponent(const Entity& e, const Component& c)
		{
			m_Components.push_back(c);
			m_IndicesMap[e] = m_Components.size() - 1;
			m_EntityMap[m_Components.size() - 1] = e;
			return true;
		}

		//template<typename Component>
		inline Component& GetComponent(const Entity& e)
		{
			return m_Components[m_IndicesMap[e]];
		}

		//template<typename Component>
		void DestroyComponent(const Entity& e)
		{
			// Remove component
			std::swap(m_Components[m_IndicesMap[e]], m_Components.back());
			m_Components.pop_back();

			// Update entity map
			m_IndicesMap[m_EntityMap[m_Components.size()]] = m_IndicesMap[e];
			m_EntityMap[m_IndicesMap[e]] = m_EntityMap[m_Components.size()];
			m_IndicesMap.erase(e);
			m_EntityMap.erase(m_Components.size());
		}
	};
}

