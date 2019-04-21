#include "Game.hpp"

Game::Game()
{
	m_systems.push_back(std::make_unique<GraphicSystem>(m_entity_mgr));
	initialize();
}

Game::~Game()
{
	for (auto& system : m_systems)
		system.reset();
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

void Game::initialize()
{
	EntityHandle entity_handle_1 = m_entity_mgr.create_entity();
	EntityHandle entity_handle_2 = m_entity_mgr.create_entity();

	Entity* entity1 = m_entity_mgr.get_entity(entity_handle_1);
	Entity* entity2 = m_entity_mgr.get_entity(entity_handle_2);

	entity1->add_component<PositionComponent>({ 1, 1, 1 });
	entity1->add_component<ColorComponent>({ 0, 255, 0, 0 });

	auto& pos = entity1->get_component<PositionComponent>();
	auto& col = entity1->get_component<ColorComponent>();
	
	col.r = 255;
	col.g = 255;
	col.b = 255;
	col.a = 255;
}
