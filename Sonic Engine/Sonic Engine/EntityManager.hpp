#pragma once
#include "ComponentManager.hpp"
#include "Entity.hpp"

class Key
{
public:
	friend class EntityManager;

	template<typename Component>
	void include_components()
	{
		ComponentTypes component = Component();
		bitset_include[component.index()] = 1;
	}

	template <typename Component1, typename Component2, typename... OtherComponents>
	void include_components()
	{
		ComponentTypes component = Component1();
		bitset_include[component.index()] = 1;
	
		component = Component2();
		bitset_include[component.index()] = 1;

		// Checks if Args contains more than 0 arguments
		if constexpr (sizeof...(OtherComponents) > 0) {
			include_components<OtherComponents...>();
		}
	}

	template<typename Component>
	void exclude_components()
	{
		ComponentTypes component = Component();
		bitset_exclude[component.index()] = 1;
	}

	template <typename Component1, typename Component2, typename... OtherComponents>
	void exclude_components()
	{
		ComponentTypes component = Component1();
		bitset_exclude[component.index()] = 1;
	
		component = Component2();
		bitset_exclude[component.index()] = 1;

		// Checks if Args contains more than 0 arguments
		if constexpr (sizeof...(OtherComponents) > 0) {
			exclude_components<OtherComponents...>();
		}
	}

	size_t get_include_count() { return bitset_include.count(); };
	size_t get_exclude_count() { return bitset_exclude.count(); };
private:
	component_bitset bitset_include;
	component_bitset bitset_exclude;
};

class EntityManager
{
public:
	EntityManager();
	~EntityManager();
	EntityHandle create_entity();
	Entity* get_entity(EntityHandle handle);
	void delete_entity(EntityHandle handle);
	std::vector<Entity*> get_entities(Key key);
private:
	std::vector<Entity*> m_entities;
	int m_index_counter;
	ComponentManager m_component_manager;
};