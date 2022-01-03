#ifndef DAY_10
#define DAY_10

#include <string>
#include <vector>

namespace day10
{
  int executeTask(int task);
  class Line
  {
    public:
      Line(std::string line);
      bool isError() { return this->errScore != 0; };
      int getErrorScore() { return this->errScore; }
      unsigned long long completeLine();
    protected:
      int errScore = 0;
      vector<char> remaining;
  };
}

#endif
