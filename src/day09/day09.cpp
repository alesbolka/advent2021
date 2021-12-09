#include <iostream>
#include <string>
#include <vector>
#include "../shared/fileReader.h"
#include "./day09.h"
#include "./Heightmap.cpp"

using namespace day09;

int day09::executeTask(int task)
{
  std::vector<std::string> input = readArrayString("./src/day09/day09.input");
  std::vector<std::string> sample = readArrayString("./src/day09/day09.sample");
  HeightMap mp(input);

  if (task == 1)
  {
    std::cout << "The endpoints on this map have a risk level of: " << mp.lowPointSum() << std::endl;
    return 0;
  }


  return 0;
}