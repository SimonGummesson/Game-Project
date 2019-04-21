#pragma once
#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "EntityManager.hpp"

class System
{
public:
	System(EntityManager& entity_manager);
	~System();

	virtual void update() = 0;
protected:
	EntityManager& m_entity_mgr;
};
#endif // !SYSTEM_HPP