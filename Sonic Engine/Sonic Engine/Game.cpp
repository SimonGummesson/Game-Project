#include "Game.hpp"

Game::Game()
{
	m_systems.push_back(std::make_unique<GraphicSystem>(m_entity_manager));
}

Game::~Game()
{
}

void Game::start()
{
	run_systems();
}

void Game::run_systems()
{
	for (auto& system : m_systems)
		system->update();
}
