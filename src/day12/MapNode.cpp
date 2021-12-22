#include <iostream>
#include <set>
#include <string>
#include <vector>
#include "./day12.h"

using namespace day12;
using std::string;
using std::vector;
using std::set;

void MapNode::connect(MapNode* other)
{
  this->connections.push_back(other);
}

void print_path(vector<MapNode*> path)
{
  char sep = ' ';
  for (MapNode* node: path)
  {
    std::cout << sep << (*node).getName();
    sep = ',';
  }
  std::cout << std::endl;
}

set<vector<MapNode*>> MapNode::consider(vector<MapNode*> origin, MapNode* end)
{
  set<vector<MapNode*>> res;
  for (MapNode* other: this->connections)
  {
    if ((*other).isSmall() && std::count(origin.begin(), origin.end(), other) > 0)
    {
      continue;
    }
    vector<MapNode*> newPath = origin;
    newPath.push_back(other);

    if (other == end)
    {
      // print_path(newPath);
      res.insert(newPath);
      continue;
    }

    set<vector<MapNode*>> innerRes = (*other).consider(newPath, end);

    for (vector<MapNode*> winner: innerRes)
    {
      res.insert(winner);
    }
  }

  return res;
}