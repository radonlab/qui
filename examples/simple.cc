#include "application.h"
#include "window.h"

int main(int argc, const char* argv[]) {
  qui::Application app(argc, argv);
  qui::Window::CreateWindow("simple", 800, 500);
  return app.Run();
}
