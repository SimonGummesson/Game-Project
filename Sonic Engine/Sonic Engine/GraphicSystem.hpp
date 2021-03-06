#pragma once
#ifndef GRAPHIC_SYSTEM_HPP
#define GRAPHIC_SYSTEM_HPP

#include <iostream>
#include <assert.h>

#include <glad/glad.h>

#include "System.hpp"

class GraphicSystem : public System
{
public:
	GraphicSystem(EntityManager& entity_mgr);
	~GraphicSystem();

	void update();
private:

};

#endif
