#include "./day05.h"
#include "./FloorMap.cpp"
#include "../shared/fileReader.h"

using namespace day05;

int day05::executeTask(int task)
{
  FloorMap map;
  auto reader = [&map, &task](std::string line) mutable
  {
    map.parseLine(line, task == 1);
  };
  readByLine("./src/day05/day05.input", reader);

  std::cout << "Found " << map.countIntersects() << " intersections" << std::endl;
  return 0;
}