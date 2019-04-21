#include "GraphicSystem.hpp"

GraphicSystem::GraphicSystem(EntityManager& entity_mgr) : System(entity_mgr)
{
}

GraphicSystem::~GraphicSystem()
{
}

void GraphicSystem::update()
{
	EntityHandle entity_handle_1 = m_entity_mgr.create_entity();
	EntityHandle entity_handle_2 = m_entity_mgr.create_entity();

	std::cout << entity_handle_1.index << " " << entity_handle_2.index << '\n';

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
	
	auto col_new = entity1->get_component<ColorComponent>();

	entity1->remove_component<ColorComponent>();
	//entity1->remove_component<PositionComponent>();
	entity1->remove_component<ColorComponent>();

	entity1->add_component<ColorComponent>({ 0, 255, 0, 0 });

	Key k;
	k.include_components<PositionComponent>();

	std::vector<Entity*> recieved_enteties = m_entity_mgr.get_entities(k);
	m_entity_mgr.delete_entity(entity_handle_2);
	m_entity_mgr.delete_entity(entity_handle_1);
	
}
