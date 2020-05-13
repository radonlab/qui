#include "application.h"
#include "window.h"

int main(int argc, char* argv[]) {
  qui::Application app(argc, argv);
  int exit_code = app.ExecuteProcess();
  if (exit_code >= 0) {
    return exit_code;
  }
  app.CreateWindow("simple", 800, 500);
  return app.Run();
}
