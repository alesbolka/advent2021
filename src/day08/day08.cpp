#include <iostream>
#include <string>
#include <vector>
#include "../shared/fileReader.h"
#include "../shared/stringHelpers.h"
#include "./day08.h"
#include "./simple.cpp"
#include "./full.cpp"

using namespace day08;

int day08::executeTask(int task)
{
  std::vector<std::string> input = readArrayString("./src/day08/day08.input");
  std::vector<std::string> sample = readArrayString("./src/day08/day08.sample");

  int total = 0;
  if (task == 1)
  {
    for (std::string line : input)
    {
      total += countSimple(line);
    }
    std::cout << "Digits 1, 4, 7 and 8 appear " << total << " times" << std::endl;
  }
  else
  {
    for (std::string line : input)
    {
      total += countFull(line);
    }
    std::cout << "Sum of output numbers: " << total << std::endl;
  }

  return 0;
}