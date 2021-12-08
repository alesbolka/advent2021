#ifndef DAY_07
#define DAY_07

#include <limits>
#include <string>
#include <array>
#include <map>

namespace day07
{
  int executeTask(int task);

  class CrabMatrix
  {
  public:
    void parseInput(std::string line);
    int findMinAlignmentFuel(int mode);

  protected:
    std::map<int, int> positions;
    int min = std::numeric_limits<int>::max();
    int max = std::numeric_limits<int>::min();
  };
}

#endif
