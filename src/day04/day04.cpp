#include <iostream>
#include <vector>
#include <string>
#include "../shared/fileReader.h"
#include "./day04.h"
#include "./BingoGame.cpp"

using namespace day04;

int executeDay04Task(int task)
{
  BingoGame game;

  std::vector<std::string> data = readArrayString("./src/day04/day04.input");
  if (task == 1) {
    game.parseInput(data);
    std::cout << "Winner board id: " << game.play() << std::endl;
    return 0;
  }

  game.parseInput(data);
  std::cout << "Last winner id: " << game.play(true) << std::endl;

  return 0;
}
