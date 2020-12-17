#pragma once
#include <vector>
#include <unordered_map>
#include <stdint.h>
#include "Entity.h"

namespace secs
{
	template <typename Component, constexpr int n = 100>
	class ComponentManager
	{
	private:
		std::vector<Component> m_Components;
		std::vector<uint32_t> m_Indices;

	public:
		ComponentManager(): m_Components(n), m_Indices(n) {};
		~ComponentManager() {};

		template<typename Component>
		bool AddComponent(const Entity& e, const Component& c)
		{
			m_Components.push_back(c);
			if (m_Indices.size() <= e.Index())
			{
				m_Indices.resize(e.Index() * 2);
			}
			m_Entities[e.Index()] = m_Components.size() - 1;
			return true;
		}

		template<typename Component>
		inline Component& GetComponent(const Entity& e)
		{
			return m_Components[m_Entities[e.Index()]];
		}

		template<typename Component>
		void DestroyComponent(const Entity& e)
		{
			// Remove component
			std::swap(m_Components[m_Entities[e.Index()]], m_Components.back());
			m_Components.pop_back();

			// Update entity map			
			for (int i = 0; i < m_Indices.size(), i++)
			{
				if (m_Indices[i] == m_Components.size())
				{
					m_Indices[i] = m_Indices[e.Index];
					m_Indices[e.Index] = nullptr;
					return;
				}
			}
		}
	};
}

