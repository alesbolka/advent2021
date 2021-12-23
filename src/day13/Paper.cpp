#include <string>
#include <vector>
#include "./day13.h"

using namespace day13;
using std::pair;
using std::string;

void Paper::addPoint(int yy, int xx)
{
  this->grid.insert(pair{yy, xx});
  this->maxX = std::max(xx, this->maxX);
  this->maxY = std::max(yy, this->maxY);
}

std::string Paper::print()
{
  string txt;
  for (int yy = 0; yy <= this->maxY; ++yy)
  {
    for (int xx = 0; xx <= this->maxX; ++xx)
    {
      if (this->grid.contains(pair{yy, xx}))
      {
        txt += '#';
      }
      else
      {
        txt += ' ';
      }
    }
    txt += '\n';
  }

  return txt;
}

void Paper::fold(char axis, int offset)
{
  if (axis == 'x')
  {
    if (offset < (this->maxX/2) || offset >= this->maxX)
    {
      throw std::out_of_range("Cannot fold on X axis at offset " + std::to_string(offset));
    }
    for (int dx = 0; dx <= this->maxX - offset; ++dx)
    {
      for (int yy = 0; yy <= this->maxY; ++yy)
      {
        if (!this->grid.contains(pair{yy, offset + dx}))
        {
          continue;
        }
        this->grid.insert(pair{yy, offset-dx});
        this->grid.erase(pair{yy, offset+dx});
      }
    }
    this->maxX = offset - 1;
  }
  else if (axis == 'y')
  {
    if (offset < (this->maxY/2) || offset >= this->maxY)
    {
      throw std::out_of_range("Cannot fold on Y axis at offset " + std::to_string(offset));
    }
    for (int dy = 0; dy <= this->maxY - offset; ++dy)
    {
      for (int xx = 0; xx <= this->maxX; ++xx)
      {
        if (!this->grid.contains(pair{offset+dy, xx}))
        {
          continue;
        }
        this->grid.insert(pair{offset - dy, xx});
        this->grid.erase(pair{offset + dy, xx});
      }
    }
    this->maxY = offset - 1;
  }
  else
  {
    throw std::invalid_argument("Invalid folding axis argument: " + string(1, axis));
  }
}