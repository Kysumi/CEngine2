#include <thread>
#include "Framework/platform/glfw/gl/GPUDriverGL.h"
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include "Browser.h"


// int UltralightWindow()
// {
// 	framework::PlatformWindowConfig config;
//
// 	auto window = framework::Application::InitWindow(config);
// 	if (!window)
// 		return -1;
//
// 	auto app = framework::Application::Create(*window.get());
//
// 	while (!glfwWindowShouldClose(window->handle())) {
// 		glfwPollEvents();
// 		app->Update();
// 		std::this_thread::sleep_for(std::chrono::milliseconds(1));
// 	}
//
// 	app.reset();
// 	window.reset();
//
// 	glfwTerminate();
//
// 	return 0;
// }


int main()
{
	sf::ContextSettings contextSettings;
	contextSettings.depthBits = 32;
	contextSettings.stencilBits = 32;
	contextSettings.antialiasingLevel = 1;
	contextSettings.minorVersion = 3;
	contextSettings.majorVersion = 3;
	
	sf::RenderWindow window(sf::VideoMode(1024, 720), "CEngine 2", sf::Style::Default, contextSettings);
	window.setVerticalSyncEnabled(true);

// 	window.setActive(true);

	Browser browser(window);

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	// /glfwMakeContextCurrent(window.getSystemHandle());

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	
		window.clear();
		
		window.setActive(true);
		//Draw ultralight
		browser.Update();
		window.setActive(false);

		//START SFML Draw 
		window.pushGLStates();
	
		window.draw(shape);
	
		window.popGLStates();
		//END SFML


		//Display
		window.display();
	}

	return 0;
}
