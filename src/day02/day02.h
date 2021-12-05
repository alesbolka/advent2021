#ifndef DAY_02
#define DAY_02

#include <string>
#include <map>

using std::invalid_argument;
using std::map;
using std::string;

namespace day02
{
  enum class SubCommand
  {
    forward,
    up,
    down,
  };

  class Submarine
  {
  public:
    static SubCommand identifyCommand(string command);
    void command(std::string instruction);
    int getResult();
  protected:
    int depth = 0;
    int posX = 0;
  };
}

#endif