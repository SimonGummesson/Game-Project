#pragma once

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "ComponentManager.hpp"
#include <assert.h>

struct EntityHandle
{
	friend class EntityManager;
protected:
	EntityHandle(int i) : index(i) {};
	bool is_valid = true;
public:
	const int index;
	EntityHandle() = delete;
};

class Entity
{
public:
	friend class EntityManager;

	template <typename Component>
	void add_component(Component data = Component())
	{
		if (m_entity_components_pointer->has_component<Component>())
			return;

		m_entity_components_pointer->add_component<Component>(std::move(data));
		return;
	}

	template <typename Component>
	void remove_component()
	{
		if (!m_entity_components_pointer->has_component<Component>())
			return;

		m_entity_components_pointer->delete_component<Component>();
	}

	template <typename Component>
	auto& get_component()
	{
		assert(m_entity_components_pointer->has_component<Component>());
		return m_entity_components_pointer->get_component<Component>();
	}

	Entity() = delete;
	int const m_index = 0;
private:
	Entity(EntityComponents* entity_components_pointer, int index) : m_entity_components_pointer(entity_components_pointer), m_index(index) {};
	~Entity();
	EntityComponents* const m_entity_components_pointer = nullptr;
};

#endif
