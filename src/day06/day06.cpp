#include <iostream>
#include <string>
#include "./day06.h"
#include "./Shoal.cpp"
#include "../shared/fileReader.h"

using namespace day06;

int day06::executeTask(int task)
{
  std::string input = readArrayString("./src/day06/day06.input")[0];
  std::string sample = readArrayString("./src/day06/day06.sample")[0];

  Shoal shoal;

  if (task == 1)
  {
    shoal.parseInput(input);
    std::cout << "After 80 days, there would be: " << shoal.observe(80) << " fish" << std::endl;
  }
  else if (task == 2)
  {
    shoal.parseInput(input);
    std::cout << "After 80 days, there would be: " << shoal.observe(256) << " fish" << std::endl;
  }

  return 0;
}
