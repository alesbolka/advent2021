#include <string>
#include <vector>
#include "./day09.h"

using namespace day09;
using std::string;
using std::vector;

HeightMap::HeightMap(vector<string> input)
{
  int yy = 0;
  for (string line : input)
  {
    if (this->sizeX == 0)
    {
      this->sizeX = line.size();
    }
    else if (this->sizeX != line.size())
    {
      throw std::invalid_argument("Line length mismatch while parsing floor map");
    }

    for (int xx = 0; xx < line.size(); ++xx)
    {
      this->floor[Coords{yy, xx}] = line[xx] - '0';
    }
    ++yy;
  }
  this->sizeY = yy;
}

int HeightMap::lowPointSum()
{
  int res = 0;
  std::cout << std::endl;
  for (auto xy : this->findLowPoints())
  {
    res += this->floor[xy] + 1;
  }
  return res;
}

vector<Coords> HeightMap::findLowPoints()
{
  vector<Coords> res;

  for (int yy = 0; yy < this->sizeY; ++yy)
  {
    for (int xx = 0; xx < this->sizeX; ++xx)
    {
      int val = this->floor[Coords{yy, xx}];
      for (Coords xy : this->getNeighbours(Coords{yy, xx}))
      {
        if (this->floor[xy] <= val)
        {
          goto HM_SKIP_CELL;
        }
      }
      res.push_back(Coords{yy, xx});
    HM_SKIP_CELL:;
    }
  }

  return res;
}

std::vector<Coords> HeightMap::getNeighbours(Coords pos)
{
  vector<Coords> res;
  auto end = this->floor.end();
  auto it = this->floor.find(Coords{pos.Y - 1, pos.X});
  if (it != end)
  {
    res.push_back((*it).first);
  }

  it = this->floor.find(Coords{pos.Y + 1, pos.X});
  if (it != end)
  {
    res.push_back((*it).first);
  }

  it = this->floor.find(Coords{pos.Y, pos.X - 1});
  if (it != end)
  {
    res.push_back((*it).first);
  }

  it = this->floor.find(Coords{pos.Y, pos.X + 1});
  if (it != end)
  {
    res.push_back((*it).first);
  }

  return res;
}