#include <iostream>
#include <vector>
#include "../shared/fileReader.h"

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

uint day01countDepthIncrements(vector<int> sonarReport, int windowSize = 1)
{
  uint counter = 0;
  int prev = 0;

  if (sonarReport.size() < windowSize)
  {
    throw invalid_argument("No elements in to count depth with");
  }

  for (auto iterator = sonarReport.begin() + windowSize; iterator != sonarReport.end(); iterator++)
  {
    int sum1 = 0;
    int sum2 = 0;

    for (int jj = 0; jj < windowSize; jj++)
    {
      sum1 += *(iterator - jj - 1);
      sum2 += *(iterator - jj);
    }

    if (sum1 < sum2)
    {
      counter++;
    }
  }

  return counter;
}

int executeDay01Task(int task)
{
  vector<int> sweepReport = readArrayInt("./src/day01/day01.input");
  uint increments, window;

  switch (task)
  {
  case 1:
    window = 1;
    break;
  case 2:
    window = 3;
    break;
  default:
    cout << "Day 1 has no task " << task << endl;
    return 1;
  }

  increments = day01countDepthIncrements(sweepReport, window);
  cout << "Increments in report with a window of width " << window << ": " << increments << endl;

  return 0;
}
