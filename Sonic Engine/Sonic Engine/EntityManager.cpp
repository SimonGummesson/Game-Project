#include "EntityManager.hpp"

EntityManager::EntityManager()
{
	m_index_counter = 0;
}

EntityManager::~EntityManager()
{
}

EntityHandle EntityManager::create_entity()
{
	m_component_manager.add_entity_data();
	EntityHandle handle(m_index_counter++);
	Entity* entity = new Entity(m_component_manager.get_entity_components_pointer(handle.index), handle.index);
	m_entities.push_back(entity);
	return handle;
}

Entity* EntityManager::get_entity(EntityHandle handle)
{
	assert(handle.is_valid);
	return m_entities[handle.index];
}

// if the deleted pointer previously has been aquired none of the changes made to that entity will have any effect
void EntityManager::delete_entity(EntityHandle handle)
{
	if (handle.is_valid)
	{
		m_component_manager.remove_entity_data(handle.index);
		delete m_entities[handle.index];
		handle.is_valid = false;
	}
}

std::vector<Entity*> EntityManager::get_entities(Key key)
{
	std::vector<Entity*> return_value;
	int include_count = key.get_include_count();
	int exclude_count = key.get_exclude_count();

	if (include_count > 0)
	{
		if (exclude_count > 0)
		{
			for (auto entity : m_entities)
			{
				if ((entity->m_entity_components_pointer->attached_components & key.bitset_exclude).count() > 0)
					continue;

				if ((entity->m_entity_components_pointer->attached_components & key.bitset_include).count() == include_count)
					return_value.push_back(entity);
			}
		}
		else
		{
			for (auto entity : m_entities)
			{
				if ((entity->m_entity_components_pointer->attached_components & key.bitset_include).count() == include_count)
					return_value.push_back(entity);
			}
		}
	}
	else
	{
		if (exclude_count > 0)
		{
			for (auto entity : m_entities)
			{
				if ((entity->m_entity_components_pointer->attached_components & key.bitset_exclude).count() > 0)
					continue;

				return_value.push_back(entity);
			}
		}
	}

	return return_value;
}
