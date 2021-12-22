#ifndef DAY_11
#define DAY_11

#include <string>
#include <vector>

namespace day11
{
  int executeTask(int task);

  class Octogrid
  {
    public:
      Octogrid(std::vector<std::string> input);
      int simulate(int steps);
      void print();
    protected:
      int grid[10][10];

      int step();
      void increment(int yy, int xx);
  };
}

#endif
