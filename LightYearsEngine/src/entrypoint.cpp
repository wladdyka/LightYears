#include "entrypoint.h"
#include "framework/application.h"

int main() {
  ly::Application* app = GetApplication();
  app->Run();

  delete app;
}
