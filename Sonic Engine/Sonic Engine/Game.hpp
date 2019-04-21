#pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include <memory>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "System.hpp"
#include "GraphicSystem.hpp"

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	void run_systems();
	void initialize();
	EntityManager m_entity_mgr;
	std::vector<std::unique_ptr<System>> m_systems;
	GLFWwindow* m_window;
};

#endif // !GAME_HPP
