#ifndef DAY_04
#define DAY_04

#include <string>
#include <vector>
#include <map>
#include <tuple>

using std::map;
using std::string;
using std::vector;

namespace day04
{
  class BingoBoard
  {
  public:
    bool done() { return this->hasWon; };
    int draw(int number);
    int size() { return this->numbers.size(); };
    void parseLine(string line);
    void reset();

  protected:
    int rows = 0;
    int cols = -1;
    int totalSum = 0;
    int gameSum = 0;
    bool hasWon = false;
    map<int, std::array<int, 2>> numbers;
    map<int, bool> gameNumbers;
    vector<int> rowHits;
    vector<int> colHits;
  };

  class BingoGame
  {
  public:
    int play(bool findLast = false);
    void parseFirstLine(string line);
    void parseInput(vector<string> lines);

  protected:
    vector<int> sequence;
    vector<BingoBoard> boards;
  };
}

#endif
