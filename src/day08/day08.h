#ifndef DAY_08
#define DAY_08

#include <string>

namespace day08
{
  int executeTask(int task);

  enum class Segments
  {
    //  aaaa
    // b    c
    // b    c
    //  dddd
    // e    f
    // e    f
    //  gggg
    a,
    b,
    c,
    d,
    e,
    f,
    g,
  };

  int countSimple(std::string line);

  class Pattern
  {
    public:
      Pattern(std::string line);
  };
}

#endif
