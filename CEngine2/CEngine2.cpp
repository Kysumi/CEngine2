#include "pch.h"
#include <iostream>
#include <Framework/Window.h>

#include <Framework/Platform.h>
#include <Framework/Window.h>
#include <Framework/Application.h>
#include <Framework/platform/win/MainLoopWin.h>
#include "Browser.h"


namespace framework {

	std::unique_ptr<Window> Application::InitWindow(PlatformWindowConfig& config) {
#ifdef FRAMEWORK_PLATFORM_GLFW
		config.width = 1024;
		config.height = 768;
		config.title = "Ultralight - Browser Sample - GLFW";
#elif FRAMEWORK_PLATFORM_WIN
		config.width = 1024;
		config.height = 768;
		config.fullscreen = false;
#endif
		return Window::Create(config);
	}

	std::unique_ptr<Application> Application::Create(Window& window) {
		return std::unique_ptr<Application>(new Browser(window));
	}

}

int main(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
    std::cout << "Hello World!\n";

	framework::PlatformWindowConfig config;
	config.width = 800;
	config.height = 600;
	//config.fullscreen = false;
	//config.hInstance = hInstance;

}
