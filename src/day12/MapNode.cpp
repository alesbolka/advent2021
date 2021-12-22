#include <iostream>
#include <set>
#include <string>
#include <vector>
#include "./day12.h"

using namespace day12;
using std::set;
using std::string;
using std::vector;

void MapNode::connect(MapNode *other)
{
  this->connections.push_back(other);
}

void print_path(vector<MapNode *> path)
{
  char sep = ' ';
  for (MapNode *node : path)
  {
    std::cout << sep << (*node).getName();
    sep = ',';
  }
  std::cout << std::endl;
}

void print_path(Path path)
{
  char sep = ' ';
  for (MapNode *node : path.nodes)
  {
    std::cout << sep << (*node).getName();
    sep = ',';
  }
  std::cout << std::endl;
}

set<vector<MapNode *>> MapNode::consider(vector<MapNode *> origin, MapNode *end)
{
  set<vector<MapNode *>> res;
  for (MapNode *other : this->connections)
  {
    if ((*other).isSmall() && std::count(origin.begin(), origin.end(), other) > 0)
    {
      continue;
    }
    vector<MapNode *> newPath = origin;
    newPath.push_back(other);

    if (other == end)
    {
      // print_path(newPath);
      res.insert(newPath);
      continue;
    }

    set<vector<MapNode *>> innerRes = (*other).consider(newPath, end);

    for (vector<MapNode *> winner : innerRes)
    {
      res.insert(winner);
    }
  }

  return res;
}

set<Path> MapNode::considerV2(Path origin, MapNode *start, MapNode *end)
{
  set<Path> res;
  for (MapNode *other : this->connections)
  {
    Path newOrigin = origin;
    if (other == start)
    {
      continue;
    }

    if ((*other).isSmall())
    {
      if (newOrigin.counts.contains(other) && newOrigin.hasDouble)
      {
        continue;
      }

      if (!newOrigin.counts.contains(other))
      {
        newOrigin.counts[other] = 0;
      }

      if (++newOrigin.counts[other] == 2)
      {
        newOrigin.hasDouble = true;
      }
    }

    newOrigin.nodes.push_back(other);

    if (other == end)
    {
      // print_path(newPath);
      res.insert(newOrigin);
      continue;
    }

    set<Path> innerRes = (*other).considerV2(newOrigin, start, end);

    for (Path winner : innerRes)
    {
      res.insert(winner);
    }
  }

  return res;
}