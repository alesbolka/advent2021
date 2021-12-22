#include <string>
#include <vector>
#include "./day12.h"
#include "./MapNode.cpp"

using namespace day12;
using std::string;
using std::vector;

CaveMap::CaveMap(vector<string> input)
{
  for (string line : input)
  {
    string waypointNameA;
    string waypointNameB;

    bool first = true;
    bool isfirstSmall = true;
    bool isSecondSmall = true;

    for (char ch: line)
    {
      if (ch == '-')
      {
        if (!first)
        {
          throw std::invalid_argument("Found second \"-\" symbol in line");
        }
        first = false;
        continue;
      }
      else if (first)
      {
        waypointNameA += ch;
        if (ch < 'a')
        {
          isfirstSmall = false;
        }
      }
      else
      {
        waypointNameB += ch;
        if (ch < 'a')
        {
          isSecondSmall = false;
        }
      }
    }

    if (!this->nodes.contains(waypointNameA))
    {
      this->nodes.insert(std::make_pair(waypointNameA, new MapNode(waypointNameA, isfirstSmall)));
    }
    if (!this->nodes.contains(waypointNameB))
    {
      this->nodes.insert(std::make_pair(waypointNameB, new MapNode(waypointNameB, isSecondSmall)));
    }

    this->nodes[waypointNameB]->connect(this->nodes[waypointNameA]);
    this->nodes[waypointNameA]->connect(this->nodes[waypointNameB]);
  }
}

set<vector<MapNode*>> CaveMap::getPaths(string start, string end)
{
  if (!this->nodes.contains(start))
  {
    throw std::invalid_argument("Start node is not in set");
  }
  if (!this->nodes.contains(end))
  {
    throw std::invalid_argument("End node is not in set");
  }

  MapNode* endNode = this->nodes[end];
  MapNode* startNode = this->nodes[start];

  return startNode->consider(vector<MapNode*>{startNode}, endNode);
}