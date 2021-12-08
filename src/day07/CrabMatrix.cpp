#include <limits>
#include <sstream>
#include "./day07.h"

using namespace day07;

int v1Fuel(int x1, int x2)
{
  return std::abs(x1 - x2);
}

int v2Fuel(int x1, int x2)
{
  if (x1 == x2)
  {
    // microoptimisation speedup
    return 0;
  }

  int diff = std::abs(x1 - x2);
  return (0.5 * diff * (1 + diff));
}

void CrabMatrix::parseInput(std::string line)
{
  std::stringstream stream(line);
  for (int ii; stream >> ii;)
  {
    if (!this->positions.contains(ii))
    {
      this->positions[ii] = 0;
    }

    this->min = std::min(this->min, ii);
    this->max = std::max(this->max, ii);
    ++this->positions[ii];

    char next = stream.peek();
    while (next == ',')
    {
      stream.ignore();
      next = stream.peek();
    }
  }
}

int CrabMatrix::findMinAlignmentFuel(int mode)
{
  int minFuel = std::numeric_limits<int>::max();

  int fuelUse;
  for (int target = this->min; target <= this->max; ++target)
  {
    fuelUse = 0;
    for (auto pos = this->positions.begin(); pos != this->positions.end(); ++pos)
    {

      fuelUse += (mode > 1 ? v2Fuel(target, pos->first) : v1Fuel(target, pos->first)) * pos->second;

      if (fuelUse > minFuel)
      {
        goto ITERATE_NEXT_POSITION;
      }
    }



    minFuel = std::min(fuelUse, minFuel);
  ITERATE_NEXT_POSITION:;
  }
  return minFuel;
}
