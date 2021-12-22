#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "./day11.h"

using namespace day11;
using std::vector;
using std::string;

Octogrid::Octogrid(vector<string> input)
{
  if (input.size() != 10)
  {
    throw std::invalid_argument("This implementation can only run a 10x10 octo-grid");
  }

  int yy = 0;
  for (string line: input)
  {
    if (line.size() != 10)
    {
      throw std::invalid_argument("This implementation can only run a 10x10 octo-grid");
    }

    int xx = 0;
    for (char ch: line)
    {
      this->grid[yy][xx] = ch - '0';
      if (this->grid[yy][xx] > 9)
      {
        throw std::invalid_argument("Invalid energy level: " + string(1, ch));
      }
      ++xx;
    }

    ++yy;
  }
}

int Octogrid::simulate(int steps)
{
  int flashes = 0;
  for (int ii = 1; ii <= steps; ++ii)
  {
    flashes += this->step();
  }

  return flashes;
}

int Octogrid::step()
{
  for (int yy = 0; yy < 10; ++yy)
  {
    for (int xx = 0; xx < 10; ++xx)
    {
      this->increment(yy, xx);
    }
  }

  int sum = 0;
  for (int yy = 0; yy < 10; ++yy)
  {
    for (int xx = 0; xx < 10; ++xx)
    {
      if (this->grid[yy][xx] > 9)
      {
        this->grid[yy][xx] = 0;
        ++sum;
      }
    }
  }

  return sum;
}

void Octogrid::increment(int yy, int xx)
{
  if (++this->grid[yy][xx] != 10)
  {
    return;
  }

  for (int dy = yy-1; dy <= yy+1; ++dy)
  {
    for (int dx = xx-1; dx <= xx+1; ++dx)
    {
      if (dy < 0 || dy > 9 || dx < 0 || dx > 9 || dx == xx && dy == yy)
      {
        continue;
      }
      this->increment(dy, dx);
    }
  }
}

void Octogrid::print()
{
  for (int yy = 0; yy < 10; ++yy)
  {
    for (int xx = 0; xx < 10; ++xx)
    {
      if (this->grid[yy][xx] > 9)
      {
        std::cout << "X";
        continue;
      }
      std::cout << this->grid[yy][xx];
    }
    std::cout << std::endl;
  }
}