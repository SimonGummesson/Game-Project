//#pragma warning(disable : 4996)

// Needed to check for memory leaks
#include <crtdbg.h>

#include <memory>
#include <windows.h>
#include <iostream>
#include "EntityManager.hpp"

int main()
{
	// Memory leak checker
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	EntityManager entity_manager;

	EntityHandle entity_handle_1 = entity_manager.create_entity();
	EntityHandle entity_handle_2 = entity_manager.create_entity();

	std::cout << entity_handle_1.index << " " << entity_handle_2.index << '\n';

	Entity* entity1 = entity_manager.get_entity(entity_handle_1);
	Entity* entity2 = entity_manager.get_entity(entity_handle_2);

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

	std::vector<Entity*> recieved_enteties = entity_manager.get_entities(k);
	entity_manager.delete_entity(entity_handle_2);
	entity_manager.delete_entity(entity_handle_1);
	getchar();
	return 0;
}
