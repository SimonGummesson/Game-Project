#include "Game.hpp"

Game::Game()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// glfw window creation
	// --------------------
	m_window = glfwCreateWindow(800, 600, "Sonic", NULL, NULL);
	if (m_window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		assert(-1);
	}
	glfwMakeContextCurrent(m_window);
	//glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	
	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		assert(-1);
	}

	m_systems.push_back(std::make_unique<GraphicSystem>(m_entity_mgr));
	initialize();
}

Game::~Game()
{
	for (auto& system : m_systems)
		system.reset();
	glfwTerminate();
}

void Game::run()
{
	 // render loop
    // -----------
    while (!glfwWindowShouldClose(m_window))
    {
        // input
        // -----
        //processInput(m_window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
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
