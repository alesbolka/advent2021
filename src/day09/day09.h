#ifndef DAY_09
#define DAY_09

#include <string>
#include <vector>

namespace day09
{
  int executeTask(int task);

  class HeightMap
  {
  public:
    HeightMap(std::vector<std::string> input);
    int lowPointSum();
  protected:
    vector<vector<int>> floor;
  };
}

#endif
