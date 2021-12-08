#include <iostream>
#include <string>
#include "../shared/fileReader.h"
#include "./day07.h"
#include "./CrabMatrix.cpp"

using namespace day07;

int day07::executeTask(int task)
{
  std::string input = readArrayString("./src/day07/day07.input")[0];
  std::string sample = readArrayString("./src/day07/day07.sample")[0];
  CrabMatrix crabbies;
  crabbies.parseInput(input);

  std::cout << "Minimum fuel used for alignment: " << crabbies.findMinAlignmentFuel(task) << std::endl;

  return 0;
}