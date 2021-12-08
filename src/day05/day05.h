#ifndef DAY_05
#define DAY_05

#include <string>
#include <vector>
#include <array>
#include <map>

namespace day05
{

  class Fissure
  {
  public:
    void parseCoordSequential(int num);
    std::vector<std::array<int, 2>> getLine(bool simple);

  protected:
    int coords[4];
    int step = 0;
  };

  class FloorMap
  {
  public:
    void parseLine(std::string line, bool simple = true);
    int countIntersects();

  protected:
    void addCoord(int y, int x);
    std::vector<Fissure> fissures;
    std::map<int, std::map<int, int>> floor;
  };

  int executeTask(int task);
}

#endif
