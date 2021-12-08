#include <iostream>
#include <string>
#include <vector>
#include "../shared/fileReader.h"
#include "./day08.h"
#include "./simple.cpp"

using namespace day08;

int day08::executeTask(int task)
{
  std::vector<std::string> input = readArrayString("./src/day08/day08.input");
  std::vector<std::string> sample = readArrayString("./src/day08/day08.sample");

  if (task == 1)
  {
    int total = 0;
    for (std::string line : input)
    {
      total += countSimple(line);
    }
    std::cout << "Digits 1, 4, 7 and 8 appear " << total << " times" << std::endl;
    return 0;
  }

  return 1;
}