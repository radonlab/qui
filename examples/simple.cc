#include "application.h"
#include "window.h"

int main(int argc, const char* argv[]) {
  qui::Application app(argc, argv);
  int exit_code = app.SpawnProcess();
  if (exit_code >= 0) {
    return exit_code;
  }
  qui::Window::CreateWindow("simple", 800, 500);
  return app.Run();
}
