#pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include <memory>

#include "System.hpp"
#include "GraphicSystem.hpp"

class Game
{
public:
	Game();
	~Game();
	void start();
private:
	void run_systems();
	EntityManager m_entity_manager;
	std::vector<std::unique_ptr<System>> m_systems;
};

#endif // !GAME_HPP
