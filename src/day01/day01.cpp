#include <iostream>
#include <vector>
#include "../shared/fileReader.cpp"

using namespace std;

vector<int> getSeed0101()
{
  vector<int> mockData = {
      199,
      200,
      208,
      210,
      200,
      207,
      240,
      269,
      260,
      263,
  };

  return mockData;
};

uint day01countDepthIncrements(vector<int> sonarReport)
{
  uint counter = 0;
  int prev = 0;

  if (sonarReport.size() < 1) {
    throw invalid_argument("No elements in to count depth with");
  }

  for (auto ii = next(sonarReport.begin()); ii != sonarReport.end(); ii++)
  {
    if (*(ii-1) < *ii) {
      counter++;
    }
  }

  return counter;
}

int executeDay01Task(int task)
{
  vector<int> sweepReport = readArrayInt("./src/day01/day1.input");
  uint increments = day01countDepthIncrements(sweepReport);
  cout << "Increments in batch: " << increments << endl;

  return 0;
}
