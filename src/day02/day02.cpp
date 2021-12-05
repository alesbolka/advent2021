#include <iostream>
#include "../shared/fileReader.h"
#include "./day02.h"

using namespace day02;

int executeDay02Task(int task)
{
  struct position {
    int depth;
    int y;
  };

  Submarine sub;

  auto reader = [&sub](std::string line) mutable
  {
    sub.command(line);
    // std::cout << line << std::endl;
  };

  if (task == 2) {
    sub.setMode(day02::InstructionMode::Day02Task2);
  }

  readByLine("./src/day02/day02.input", reader);

  std::cout << "Sub course plotted with: " << sub.getResult() << std::endl;
  return 0;
}
