#include "pch.h"
#include <iostream>
#include <Framework/Window.h>

#include <Framework/Platform.h>
#include <Framework/Application.h>
#include "Browser.h"
#include <thread>
#include "Framework/platform/glfw/gl/GPUDriverGL.h"
#include <Ultralight/platform/Platform.h>
#include "CEUI.h"
#include <SFML/Graphics.hpp>


namespace framework {
	//Will strip this out.
	std::unique_ptr<Window> Application::InitWindow(PlatformWindowConfig& config) {

	config.width = 1024;
	config.height = 768;
	config.title = "CEngine2";

		return Window::Create(config);
	}

	std::unique_ptr<Application> Application::Create(Window& window) {
		return std::unique_ptr<Application>(new Browser(window));
	}
}

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
	const auto width = 1024;
	const auto height = 720;
	const auto asset_dir = "assets/";

	auto driver = new ultralight::GPUDriverGL(width, height, 1.f);

	auto& platform = ultralight::Platform::instance();

	ultralight::Config config;
	// config.face_winding = gpu_context_->face_winding();
	config.device_scale_hint = 1.f;
	config.use_distance_field_fonts = false;//window_.scale() != 1.0f; // Only use SDF fonts for high-DPI
	config.use_distance_field_paths = true;

	platform.set_config(config);
	platform.set_gpu_driver(driver);

	platform.set_font_loader(framework::CreatePlatformFontLoader());
	platform.set_file_system(framework::CreatePlatformFileSystem(asset_dir));

	ultralight::RefPtr<ultralight::Renderer> renderer = ultralight::Renderer::Create();
	
	auto UI =  CEUI(*renderer.get(), driver, width, height);

	//END ultralight setup

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	
		window.clear();
	
		//START SFML Draw 
		window.pushGLStates();
	
		window.draw(shape);
	
		window.popGLStates();
		//END SFML Draw
	
		UI.Update();
		
		window.display();
	}

	return 0;
}
