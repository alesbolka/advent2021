#include <string>
#include <vector>
#include "./day09.h"

using namespace day09;
using std::string;
using std::vector;

HeightMap::HeightMap(vector<string> input)
{
  for (string line : input)
  {
    vector<int> rowVector;
    for (int ii = 0; ii < line.size(); ++ii)
    {
      rowVector.push_back(line[ii] - '0');
    }
    this->floor.push_back(rowVector);
  }
}

int HeightMap::lowPointSum()
{
  int res = 0;
  for (int yy = 0; yy < this->floor.size(); ++yy)
  {
    for (int xx = 0; xx < this->floor[yy].size(); ++xx)
    {
      if (yy > 0)
      {
        if (this->floor[yy - 1][xx] <= this->floor[yy][xx])
        {
          goto SKIP_CELL;
        }
      }

      if (yy < (this->floor.size() - 1))
      {
        if (this->floor[yy + 1][xx] <= this->floor[yy][xx])
        {
          goto SKIP_CELL;
        }
      }

      if (xx < (this->floor[yy].size() - 1))
      {
        if (this->floor[yy][xx+1] <= this->floor[yy][xx])
        {
          goto SKIP_CELL;
        }
      }

      if (xx > 0)
      {
        if (this->floor[yy][xx-1] <= this->floor[yy][xx])
        {
          goto SKIP_CELL;
        }
      }

      res += this->floor[yy][xx] + 1;
    SKIP_CELL:;
    }
  }
  return res;
}