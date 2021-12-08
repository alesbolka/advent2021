#include <iostream>
#include "./day05.h"

using namespace day05;

void Fissure::parseCoordSequential(int num)
{
  this->coords[this->step] = num;
  if (++this->step > 4)
  {
    throw std::invalid_argument("Too many coordinates in a line");
  }
}

std::vector<std::array<int, 2>> Fissure::getLine(bool simple)
{
  std::vector<std::array<int, 2>> res;
  if (this->coords[0] == this->coords[2])
  {
    int min = std::min(this->coords[1], this->coords[3]);
    int max = std::max(this->coords[1], this->coords[3]);

    for (min; min <= max; ++min)
    {
      res.push_back(std::array<int, 2>{this->coords[0], min});
    }
  }
  else if (this->coords[1] == this->coords[3])
  {
    int min = std::min(this->coords[0], this->coords[2]);
    int max = std::max(this->coords[0], this->coords[2]);

    for (min; min <= max; ++min)
    {
      res.push_back(std::array<int, 2>{min, this->coords[1]});
    }
  }
  else if (!simple)
  {
    int yy = this->coords[0];
    int xx = this->coords[1];
    int dy = (this->coords[0] - this->coords[2]) > 0 ? -1 : 1;
    int dx = (this->coords[1] - this->coords[3]) > 0 ? -1 : 1;

    for (yy; yy != this->coords[2]; yy += dy)
    {
      res.push_back(std::array<int, 2>{yy, xx});
      xx += dx;
    }
    res.push_back(std::array<int, 2>{this->coords[2], this->coords[3]});
  }

  return res;
}