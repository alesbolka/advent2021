#include <map>
#include <string>
#include <sstream>
#include "./day05.h"
#include "./Fissure.cpp"

using namespace day05;
using std::string;

void FloorMap::parseLine(string line, bool simple)
{
  std::stringstream stream(line);
  Fissure fiss;
  for (int ii; stream >> ii;)
  {
    fiss.parseCoordSequential(ii);
    char next = stream.peek();
    while(next == ',' || next == ' ' || next == '-' || next == '>')
    {
      stream.ignore();

      next = stream.peek();
    }
  }

  this->fissures.push_back(fiss);

  for (std::array<int, 2> spot: fiss.getLine(simple))
  {
    if (!this->floor.contains(spot[0]))
    {
      this->floor.insert(std::pair(spot[0], std::map<int, int>{}));
    }

    if (!this->floor[spot[0]].contains(spot[1]))
    {
      this->floor[spot[0]].insert(std::pair(spot[1], 0));
    }

    ++this->floor[spot[0]][spot[1]];
  }
}

int FloorMap::countIntersects()
{
  int res = 0;
  for (std::pair<const int, std::map<int, int>> row : this->floor) {
    for (std::pair<const int, const int> count: row.second)
    {
      if (count.second >= 2)
      {
        ++res;
      }
    }
  }
  return res;
}
