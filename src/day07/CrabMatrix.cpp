#include <limits>
#include <sstream>
#include "./day07.h"

using namespace day07;

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

int CrabMatrix::findMinAlignmentFuel()
{
  int minFuel = std::numeric_limits<int>::max();

  int fuelUse;
  for (int target = 0; target <= this->max; ++target)
  {
    fuelUse = 0;
    for (auto pos = this->positions.begin(); pos != this->positions.end(); ++pos)
    {
      fuelUse += std::abs(pos->first - target) * pos->second;

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