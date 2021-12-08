#include <sstream>
#include <string>
#include "./day08.h"

using namespace day08;
using std::string;

int day08::countSimple(string line)
{
  bool output = false;
  int res = 0;
  std::stringstream stream(line);

  for (string segment; stream >> segment;)
  {
    if (segment == "|")
    {
      output = true;
      continue;
    }

    if (!output) {
      continue;
    }

    if (segment.size() == 2 || segment.size() == 3 || segment.size() == 4 || segment.size() == 7)
    {
      ++res;
    }
  }

  return res;
}
