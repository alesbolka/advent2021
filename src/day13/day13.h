#ifndef DAY_13
#define DAY_13

#include <set>
#include <string>
#include <vector>

using std::set;
using std::vector;
using std::pair;

namespace day13
{
  int executeTask(int task);

  class Paper
  {
    public:
      void addPoint(int yy, int xx);
      void fold(char axis, int offset);
      int visible() { return this->grid.size(); };
      std::string print();
    protected:
      set<pair<int, int>> grid;
      int maxX = 0;
      int maxY = 0;
  };
}

#endif
