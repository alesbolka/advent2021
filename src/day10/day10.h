#ifndef DAY_10
#define DAY_10

#include <string>

namespace day10
{
  int executeTask(int task);
  class Line
  {
    public:
      Line(std::string line);
      bool isComplete() { return this->complete; };
      bool isError() { return this->errScore != 0; };
      int getErrorScore() { return this->errScore; }
    protected:
      bool complete = false;
      int errScore = 0;
  };
}

#endif
