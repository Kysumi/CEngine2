#include <Framework/GPUContext.h>
#include <Framework/platform/glfw/PlatformGLFW.h>
#include <Framework/platform/glfw/gl/GPUDriverGL.h>
// #include <glad/glad.h>
#include <SFML/Window/Window.hpp>
#include <iostream>

namespace framework {

class GPUContextGL : public GPUContext {
protected:
  std::unique_ptr<ultralight::GPUDriver> driver_;
  //PlatformWindowHandle window_;
public:
  GPUContextGL(const sf::Window& window, bool enable_vsync){ //: window_(window.getSystemHandle()) {
    //glfwMakeContextCurrent(window_);
    gladLoadGLLoader((GLADloadproc)sf::Context::getFunction);
    //glfwSwapInterval(enable_vsync? 1 : 0);
    driver_.reset(new ultralight::GPUDriverGL(window.getSize().x, window.getSize().y, (GLfloat)1.f));
  }

  virtual ~GPUContextGL() {}

  virtual ultralight::GPUDriver* driver() const override { return driver_.get(); }

  virtual ultralight::FaceWinding face_winding() const override { return ultralight::kFaceWinding_CounterClockwise; }

  virtual void BeginDrawing() override {}

  virtual void EndDrawing() override {}

  // Should only be called during drawing phase
  virtual void PresentFrame() override {
    //glfwSwapBuffers(window_);
	  std::cout << "Temp" << std::endl;
  }

  virtual void Resize(int width, int height) override {
    ultralight::GPUDriverGL* driver_gl = static_cast<ultralight::GPUDriverGL*>(driver_.get());
    driver_gl->ResizeViewport(width, height);
  }
};

std::unique_ptr<GPUContext> GPUContext::Create(const sf::Window& window, bool enable_vsync) {
  return std::unique_ptr<GPUContext>(new GPUContextGL(window, enable_vsync));
}

}  // namespace framework