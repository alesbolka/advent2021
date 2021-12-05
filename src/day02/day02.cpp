#include <iostream>
#include "../shared/fileReader.h"
#include "./day02.h"

using day02::Submarine;

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

  readByLine("./src/day02/day2.input", reader);

  std::cout << "Sub course plotted with: " << sub.getResult() << std::endl;
  return 0;
}
