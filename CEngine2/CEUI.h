#pragma once
#include "Framework/platform/glfw/gl/GPUDriverGL.h"
#include <Ultralight/Renderer.h>
#include "Framework/Overlay.h"

namespace framework {
	class Window;
}

class CEUI : public framework::Overlay,
			 public ultralight::LoadListener
{
public:
	CEUI(ultralight::Ref<ultralight::Renderer> renderer, ultralight::GPUDriver* driver, framework::Window& window);
	~CEUI();

	void Update();

	void drawTemp();

private:
	const int width_ = 1024;
	const int height_ = 720;
	const char* asset_dir_ = "assets/";

	ultralight::GPUDriver *driver_;
	ultralight::RefPtr<ultralight::Renderer> renderer_;
};
