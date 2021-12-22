#ifndef DAY_12
#define DAY_12

#include <set>
#include <string>
#include <vector>
#include <map>

namespace day12
{
  int executeTask(int task);

  struct Path;

  class MapNode
  {
    public:
      MapNode(std::string name, bool small): name(name), small(small){};
      bool isSmall() { return this->small; };
      void connect(MapNode* other);
      std::set<std::vector<MapNode*>> consider(vector<MapNode*> origin, MapNode* end);
      std::set<Path> considerV2(Path origin, MapNode* start, MapNode* end);
      std::string getName() { return this->name; };
    protected:
      std::vector<MapNode*> connections;
      std::string name;
      bool small;
  };

  struct Path
  {
    std::vector<MapNode*> nodes;
    std::map<MapNode*, int> counts;
    bool hasDouble = false;

    bool operator==(const Path& other) const
    {
      return nodes == other.nodes;
    }

    bool operator<(const Path& other) const
    {
      return nodes < other.nodes;
    }
  };

  class CaveMap
  {
    public:
      CaveMap(std::vector<std::string> input);
      std::set<std::vector<MapNode*>> getPaths(std::string start = "start", std::string end = "end");
      std::set<Path> getPathsV2(std::string start = "start", std::string end = "end");
    protected:
      std::map<std::string, MapNode*> nodes;
  };
}

#endif
