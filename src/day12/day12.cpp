#include <iostream>
#include <string>
#include <set>
#include <string>
#include <vector>
#include "../shared/fileReader.h"
#include "./day12.h"
#include "./CaveMap.cpp"

using namespace day12;

int day12::executeTask(int task)
{
  std::vector<std::string> input = readArrayString("./src/day12/input.txt");
  std::vector<std::string> sample = readArrayString("./src/day12/sample.txt");
  std::vector<std::string> sample2 = readArrayString("./src/day12/sample2.txt");
  std::vector<std::string> sample3 = readArrayString("./src/day12/sample3.txt");

  CaveMap map(input);

  if (task == 1)
  {
    std::set<std::vector<MapNode*>> paths = map.getPaths();
    std::cout << "Found " << paths.size() << " paths" << std::endl;
    return 0;
  }

  return 1;
}