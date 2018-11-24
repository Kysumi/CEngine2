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
	CEUI(ultralight::Ref<ultralight::Renderer> renderer, ultralight::GPUDriverGL* driver, int width, int height);
	~CEUI();

	void Update();

private:
	const int width_ = 1024;
	const int height_ = 720;
	const char* asset_dir_ = "assets/";

	ultralight::GPUDriverGL *driver_;
	ultralight::RefPtr<ultralight::Renderer> renderer_;
};
