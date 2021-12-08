#include <sstream>
#include "./day06.h"

using namespace day06;

void Shoal::parseInput(std::string line)
{
  std::stringstream stream(line);
  for (int ii; ii < 9; ++ii)
  {
    this->initial[ii] = 0;
  }

  for (unsigned long long int ii; stream >> ii;)
  {
    if (ii <= 8)
    {
      ++this->initial[ii];
    }
    else
    {
      throw std::invalid_argument("Unable to parse fish that will spawn after more than 8 days at the moment");
    }

    char next = stream.peek();
    while (next == ',')
    {
      stream.ignore();
      next = stream.peek();
    }
  }
}

unsigned long long int Shoal::observe(int days)
{
  unsigned long long int sum = 0;
  for (int ii = 0; ii < 9; ++ii)
  {
    this->fish[ii] = this->initial[ii];
    sum += this->fish[ii];
  }

  unsigned long long int newFish;
  for (int day = 1; day <= days; ++day)
  {
    newFish = this->fish[0];
    for (int ii = 1; ii < 9; ++ii)
    {
      this->fish[ii - 1] = this->fish[ii];
    }
    this->fish[6] += newFish;
    this->fish[8] = newFish;
    sum += newFish;
  }

  return sum;
}
