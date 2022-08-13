#include "engine.h"
#include "log.h"

int main() {
  Log::debug("App is starting ...");
  Engine  engine = Engine::getInstance();
  engine.init();
  engine.run();
  engine.destory();
  return 0;
}
