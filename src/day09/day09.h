#ifndef DAY_09
#define DAY_09

#include <string>
#include <map>
#include <vector>

namespace day09
{
  int executeTask(int task);

  struct Coords
  {
    int Y;
    int X;
  };
  bool operator==(const Coords &one, const Coords &two)
  {
    return one.X == two.X && one.Y == two.Y;
  }
  bool operator<(const Coords &one, const Coords &two)
  {
    if (one.Y == two.Y)
    {
      return one.X < two.X;
    }
    return one.Y < two.Y;
  }

  class HeightMap
  {
  public:
    HeightMap(std::vector<std::string> input);
    int lowPointSum();
    int basinSizeMulti();
    std::vector<Coords> getNeighbours(Coords pos);

  protected:
    std::vector<Coords> findLowPoints();
    std::map<Coords, int> floor;
    int sizeY = 0;
    int sizeX = 0;
  };
}

#endif
