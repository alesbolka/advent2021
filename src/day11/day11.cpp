#include <iostream>
#include "../shared/fileReader.h"
#include "./day11.h"
#include "./OctoGrid.cpp"

using namespace day11;

int day11::executeTask(int task)
{
  std::vector<std::string> input = readArrayString("./src/day11/input.txt");
  std::vector<std::string> sample = readArrayString("./src/day11/sample.txt");

  Octogrid grid(input);

  if (task == 1)
  {
    int res = grid.simulate(100);
    std::cout << "After 100 steps there are " << res << " flashes" << std::endl;
    return 0;
  }

  int res = grid.synchronise();
  std::cout << "The octopi synchronise on step " << res << std::endl;

  return 0;
}