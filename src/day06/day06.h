#ifndef DAY_06
#define DAY_06

#include <string>
#include <array>
#include <map>

namespace day06
{
  int executeTask(int task);

  class Shoal
  {
  public:
    void parseInput(std::string line);
    unsigned long long int observe(int days);

  protected:
    unsigned long long int fish[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    unsigned long long int initial[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  };
}

#endif
