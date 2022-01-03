#include <iostream>
#include "../shared/fileReader.h"
#include "./dayXX.h"

using namespace dayXX;

int dayXX::executeTask(int task)
{
  std::vector<std::string> input = readArrayString("./src/dayXX/input.txt");
  std::vector<std::string> sample = readArrayString("./src/dayXX/sample.txt");

  if (task == 1)
  {
    return 0;
  }

  return 1;
}