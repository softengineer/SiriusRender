#include "engine.h"

int main() {
  Engine  engine = Engine::getInstance();
  engine.init();
  engine.run();
  engine.destory();
  return 0;
}
