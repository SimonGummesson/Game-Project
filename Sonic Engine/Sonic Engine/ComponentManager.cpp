#include "ComponentManager.hpp"
#include <iostream>
ComponentManager::ComponentManager()
{
}

ComponentManager::~ComponentManager()
{
	for (auto component_data : m_entity_components)
	{
		if (component_data != nullptr)
			delete component_data;
	}
}

void ComponentManager::remove_entity_data(int index)
{
	delete m_entity_components[index];
}

int ComponentManager::add_entity_data()
{
	m_entity_components.push_back(new EntityComponents());
	return m_entity_components.size() - 1;
}

EntityComponents * ComponentManager::get_entity_components_pointer(int index)
{
	return m_entity_components[index];
}
