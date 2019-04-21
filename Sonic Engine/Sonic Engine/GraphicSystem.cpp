#include "GraphicSystem.hpp"

GraphicSystem::GraphicSystem(EntityManager& entity_mgr) : System(entity_mgr)
{
}

GraphicSystem::~GraphicSystem()
{
}

void GraphicSystem::update()
{
	Key k;
	k.include_components<PositionComponent>();

	std::vector<Entity*> recieved_enteties = m_entity_mgr.get_entities(k);
}
