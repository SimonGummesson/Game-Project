#pragma once

#ifndef COMPONENT_MANAGER_HPP
#define COMPONENT_MANAGER_HPP

#include <vector>
#include <map>
#include <bitset> 
#include <variant>

#include "Component_types.hpp"    

using component_bitset = std::bitset<std::variant_size_v<ComponentTypes>>;

struct EntityComponents
{
	component_bitset attached_components;
	EntityComponents() {};
	~EntityComponents() {};
	std::map<size_t, ComponentTypes> components;

	template <typename Component>
	void add_component(Component data)
	{
		ComponentTypes type = data;
		int index = type.index();
		attached_components[index] = 1;
		components[index] = type;
	}

	template <typename Component>
	auto& get_component()
	{
		ComponentTypes type = Component();
		return std::get<Component>(components[type.index()]);
	}

	template <typename Component>
	bool has_component()
	{
		ComponentTypes component = Component();
		return attached_components[component.index()];
	}

	template <typename Component>
	void delete_component()
	{
		ComponentTypes type = Component();
		int index = type.index();

		attached_components[index] = 0;
		std::map<size_t, ComponentTypes>::iterator it = components.find(index);
		components.erase(it);
	}
};

class ComponentManager
{
	friend EntityComponents;
public:
	ComponentManager();
	~ComponentManager();

	void remove_entity_data(int index);
	int add_entity_data();

	template <typename Component>
	void add_component(int entity, Component&& data)
	{
		m_entity_components[entity]->add_component(std::move(data));
	}

	template <typename Component>
	auto& get_component(int index)
	{
		return m_entity_components[index]->get_component<Component>();
	}
	
	template <typename Component>
	bool has_component(int index)
	{
		return m_entity_components[index]->has_component<Component>();
	}

	template <typename Component>
	void delete_component(int index)
	{
		return m_entity_components[index]->delete_component<Component>();
	}

	EntityComponents* get_entity_components_pointer(int index);
private:
	std::vector<EntityComponents*> m_entity_components;
};

#endif
