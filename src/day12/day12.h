#ifndef DAY_12
#define DAY_12

#include <set>
#include <string>
#include <vector>
#include <map>

namespace day12
{
  int executeTask(int task);

  class MapNode
  {
    public:
      MapNode(std::string name, bool small): name(name), small(small){};
      bool isSmall() { return this->small; };
      void connect(MapNode* other);
      std::set<std::vector<MapNode*>> consider(vector<MapNode*> origin, MapNode* end);
      std::string getName() { return this->name; };
    protected:
      std::vector<MapNode*> connections;
      std::string name;
      bool small;
  };

  class CaveMap
  {
    public:
      CaveMap(std::vector<std::string> input);
      std::set<std::vector<MapNode*>> getPaths(std::string start = "start", std::string end = "end");
    protected:
      std::map<std::string, MapNode*> nodes;
  };
}

#endif
