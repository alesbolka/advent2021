#include "./dayXX.h"
#include "../shared/fileReader.h"

using namespace dayXX;

int dayXX::executeTask(int task)
{
  std::vector<std::string> input = readArrayString("./src/dayXX/dayXX.input");
  std::vector<std::string> sample = readArrayString("./src/dayXX/dayXX.sample");

  if (task == 1)
  {
    return 0;
  }

  return 1;
}