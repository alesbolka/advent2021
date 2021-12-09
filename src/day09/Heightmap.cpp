#include <string>
#include <vector>
#include <map>
#include "./day09.h"

using namespace day09;
using std::map;
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

vector<Coords> HeightMap::getNeighbours(Coords pos)
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

int HeightMap::basinSizeMulti()
{
  int basinSizes[3] = {0, 0, 0};
  for (Coords xy : this->findLowPoints())
  {
    map<Coords, bool> processed{};
    vector<Coords> toProcess{xy};

    while (toProcess.size() > 0)
    {
      Coords current = (*(toProcess.end() - 1));
      toProcess.pop_back();

      if (processed.contains(current))
      {
        continue;
      }
      processed[current] = true;

      // Every neighbour must have a value that is higher than current, but not 9
      for (Coords neighbour : this->getNeighbours(current))
      {
        if (
            !processed.contains(neighbour) &&
            this->floor[current] < this->floor[neighbour] &&
            this->floor[neighbour] < 9)
        {
          toProcess.push_back(neighbour);
        }
      }
    }

    if (processed.size() >= basinSizes[0])
    {
      basinSizes[2] = basinSizes[1];
      basinSizes[1] = basinSizes[0];
      basinSizes[0] = processed.size();
    }
    else if (processed.size() >= basinSizes[1])
    {
      basinSizes[2] = basinSizes[1];
      basinSizes[1] = processed.size();
    }
    else if (processed.size() >= basinSizes[2])
    {
      basinSizes[2] = processed.size();
    }
  }

  return basinSizes[2] * basinSizes[1] * basinSizes[0];
}
