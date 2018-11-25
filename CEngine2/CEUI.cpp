#include "CEUI.h"
#include "Framework/Window.h"

CEUI::CEUI(ultralight::Ref<ultralight::Renderer> renderer, ultralight::GPUDriver* driver, framework::Window& window):
	Overlay(renderer, driver, window.width(), 79, 0, 0, window.scale())
{
	renderer_ = renderer;
	driver_ = driver;

	//Setting up the view.
	view()->set_load_listener(this);
	view()->LoadURL("file:///ui.html");
}

CEUI::~CEUI()
{
	view()->set_load_listener(nullptr);
}

void CEUI::Update()
{
	// Update internal logic (timers, event callbacks, etc.)
	renderer_->Update();

	driver_->BeginSynchronize();

	// Render all active views to command lists and dispatch calls to GPUDriver
	renderer_->Render();

	driver_->EndSynchronize();

	// Draw any pending commands to screen
	if (driver_->HasCommandsPending())
	{
		driver_->DrawCommandList();

		// Perform any additional drawing (Overlays) here...
		//DrawOverlays();

		// Flip buffers here.
		Draw();
	}
}

void CEUI::drawTemp()
{
	Draw();
}
