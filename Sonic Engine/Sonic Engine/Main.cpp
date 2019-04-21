//#pragma warning(disable : 4996)

// Needed to check for memory leaks
#include <crtdbg.h>

#include <memory>
#include <windows.h>
#include <iostream>
#include "EntityManager.hpp"
#include "Game.hpp"
int main()
{
	// Memory leak checker
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Game game;
	game.start();

	return 0;
}
