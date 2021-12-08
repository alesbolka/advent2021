#include "./day03.h"

#include <iostream>
#include <bitset>

using std::bitset;
using std::string;
using std::vector;
using namespace day03;

bool getCriteria(bool mostCommon, int length0, int length1)
{
  if (mostCommon)
  {
    return length1 >= length0 ? 1 : 0;
  }

  return length1 < length0 ? 1 : 0;
}

void DiagnosticsReport::parseReportLine(string line)
{
  ++this->linesParsed;
  for (auto it = line.begin(); it != line.end(); ++it)
  {
    int pos = it - line.begin();

    if (this->bitSum.size() < (pos + 1))
    {
      this->bitSum.push_back(0);
    }

    if (*it == '1')
    {
      ++this->bitSum[pos];
    }
  }
}

void DiagnosticsReport::parseReportLineV2(string line)
{
  if (this->rowBitLength == 0)
  {
    this->rowBitLength = line.size();
  }
  else if (this->rowBitLength != line.size())
  {
    throw std::invalid_argument("Line length mismatch");
  }

  this->numberVector.push_back(bitset<12>(line));
}

/**
 * There are probably some very smart solutions, but I felt lazy on a Sunday and behind schedule
 * One could just invert the relevant bits in one of these two numbers to get the other for example
 */
int DiagnosticsReport::getGamma()
{
  int num = 1;
  int res = 0;

  for (int ii = this->bitSum.size() - 1; ii >= 0; --ii)
  {
    if (this->bitSum[ii] > this->linesParsed / 2)
    {
      res += num;
    }
    num *= 2;
  }
  return res;
}

int DiagnosticsReport::getEpsilon()
{
  int num = 1;
  int res = 0;

  for (int ii = this->bitSum.size() - 1; ii >= 0; --ii)
  {
    if (this->bitSum[ii] < this->linesParsed / 2)
    {
      res += num;
    }
    num *= 2;
  }
  return res;
}

int DiagnosticsReport::findByCriteria(bool mostCommon)
{
  int currentPos = this->rowBitLength;
  vector<bitset<12>> current = this->numberVector;

  while (currentPos > 0 && current.size() > 1)
  {
    vector<bitset<12>> next0;
    vector<bitset<12>> next1;
    --currentPos;
    for (int ii = 0; ii < current.size(); ++ii)
    {
      (current[ii].test(currentPos) ? next1 : next0).push_back(current[ii]);
    }

    current = getCriteria(mostCommon, next0.size(), next1.size()) ? next1 : next0;
  }

  if (current.size() != 1)
  {
    throw std::length_error("Expected 1 result");
  }

  return (int)(current[0].to_ulong());
}