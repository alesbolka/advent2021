#ifndef DAY_02
#define DAY_02

#include <string>
#include <map>

using std::invalid_argument;
using std::map;
using std::string;

namespace day02
{
  enum class InstructionMode
  {
    Day02Task1,
    Day02Task2,
  };
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

    int getResult();
    void command(std::string instruction);
    void setMode(InstructionMode newMode) { mode = newMode; };

  protected:
    InstructionMode mode = InstructionMode::Day02Task1;
    int depth = 0;
    int posX = 0;
    int aim = 0;

    void commandD2T1(SubCommand command, int val);
    void commandD2T2(SubCommand command, int val);
  };
}

#endif