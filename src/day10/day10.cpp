#include <iostream>
#include <string>
#include <vector>
#include "../shared/fileReader.h"
#include "../shared/stringHelpers.h"
#include "./day10.h"
#include "./Line.cpp"

using namespace day10;

int day10::executeTask(int task)
{
  std::vector<std::string> input = readArrayString("./src/day10/day10.input");
  std::vector<std::string> sample = readArrayString("./src/day10/day10.sample");

  if (task == 1)
  {
    int sum = 0;
    for (std::string txt : input)
    {
      Line line(txt);
      if (line.isError())
      {
        sum += line.getErrorScore();
        continue;
      }
    }
    std::cout << "Syntax error score: " << sum << std::endl;
    return 0;
  }

  return 1;
}