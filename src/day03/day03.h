#ifndef DAY_03
#define DAY_03
#include <string>
#include <vector>
#include <bitset>

using std::bitset;
using std::string;
using std::vector;

namespace day03
{
  class DiagnosticsReport
  {
  public:
    int getGamma();
    int getEpsilon();
    int findByCriteria(bool mostCommon);

    void parseReportLine(string line);
    void parseReportLineV2(string line);

  protected:
    vector<int> bitSum;
    vector<bitset<12>> numberVector;
    int linesParsed = 0;
    int rowBitLength = 0;
    int firstSum = 0;
  };
}

#endif