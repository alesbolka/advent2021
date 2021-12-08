#include <sstream>
#include <string>
#include <map>
#include <vector>
#include "./day08.h"

using namespace day08;
using std::string;
using stringHelpers::strCommon;
using stringHelpers::strDiff;

int day08::countFull(string line)
{
  bool output = false;
  int res = 0;
  std::stringstream stream(line);

  std::map<int, std::vector<string>> unknowns;
  std::map<string, int> dict;
  std::map<int, string> knowns;
  std::vector<string> digits;

  // Parse input
  for (string segment; stream >> segment;)
  {
    std::sort(segment.begin(), segment.end());

    if (!output && segment != "|")
    {
      if (segment.size() == 2)
      {
        dict[segment] = 1;
        knowns[1] = segment;
      }
      else if (segment.size() == 3)
      {
        knowns[7] = segment;
        dict[segment] = 7;
      }
      else if (segment.size() == 4)
      {
        knowns[4] = segment;
        dict[segment] = 4;
      }
      else if (segment.size() == 7)
      {
        knowns[8] = segment;
        dict[segment] = 8;
      }
      else
      {
        unknowns[segment.size()].push_back(segment);
      }
    }
    else if (segment == "|")
    {
      output = true;
    }
    else
    {
      digits.push_back(segment);
    }
  }

  // Map 5-segment digits
  for (string p5: unknowns[5])
  {
    if (strCommon(knowns[1], p5) == knowns[1])
    {
      knowns[3] = p5;
      dict[p5] = 3;
    }
    else if (strCommon(knowns[4], p5).size() == 3)
    {
      knowns[5] = p5;
      dict[p5] = 5;
    }
    else
    {
      knowns[2] = p5;
      dict[p5] = 2;
    }
  }

  // Map 6-segment digits
  for (string p6: unknowns[6])
  {
    if (strCommon(knowns[1], p6).size() == 1)
    {
      knowns[6] = p6;
      dict[p6] = 6;
    }
    else if (strCommon(knowns[3], p6).size() == 5)
    {
      knowns[9] = p6;
      dict[p6] = 9;
    }
    else {
      knowns[0] = p6;
      dict[p6] = 0;
    }
  }

  int factor = 1;
  for (int ii = digits.size() - 1; ii >= 0; --ii)
  {
    res += dict[digits[ii]] * factor;
    factor *= 10;
  }

  return res;
}