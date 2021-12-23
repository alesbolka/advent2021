#include <iostream>
#include <sstream>
#include "../shared/fileReader.h"
#include "./day13.h"
#include "./Paper.cpp"

using namespace day13;
using std::string;

int day13::executeTask(int task)
{
  std::vector<string> input = readArrayString("./src/day13/input.txt");
  std::vector<string> sample = readArrayString("./src/day13/sample.txt");

  Paper pap;
  bool foldMode = false;

  for (string line: input)
  {
    if (line.size() < 1)
    {
      foldMode = true;
      continue;
    }

    if (!foldMode)
    {
      std::istringstream stream(line);
      int xx, yy;
      stream >> xx;
      if (stream.peek() == ',')
      {
        stream.ignore();
      }
      stream >> yy;

      pap.addPoint(yy, xx);
      continue;
    }

    pap.fold(line[11], std::atoi(line.substr(13).c_str()));

    if (task == 1)
    {
      std::cout << "There are " << pap.visible() << " dots." << std::endl;
      return 0;
    }
  }

  std::cout << pap.print() << std::endl;

  return 0;
}