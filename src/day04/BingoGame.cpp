#include <iostream>
#include <sstream>

#include "./day04.h"
#include "./BingoBoard.cpp"

using namespace day04;

void BingoGame::parseInput(std::vector<std::string> lines)
{
  BingoBoard board;
  int boardSize = -1;

  for (vector<string>::iterator line = lines.begin(); line != lines.end(); ++line)
  {
    if (line == lines.begin())
    {
      this->parseFirstLine(*line);
      continue;
    }

    if ((*line).size() < 1)
    {
      if (board.size() > 0)
      {
        this->boards.push_back(board);
        if (boardSize == -1)
        {
          boardSize = board.size();
        }
        else if (boardSize != board.size())
        {
          throw std::invalid_argument("Board size mismatch");
        }

        board = BingoBoard();
      }
      continue;
    }

    board.parseLine(*line);
  }

  if (board.size() > 0)
  {
    this->boards.push_back(board);
  }
}

void BingoGame::parseFirstLine(std::string line)
{
  std::stringstream stream(line);

  for (int ii; stream >> ii;)
  {
    this->sequence.push_back(ii);
    while (stream.peek() == ' ' || stream.peek() == ',')
    {
      stream.ignore();
    }
  }
}

int BingoGame::play()
{
  if (this->boards.size() < 1)
  {
    throw std::invalid_argument("No boards to play with");
  }

  if (this->sequence.size() < 1)
  {
    throw std::invalid_argument("No number order to play with");
  }

  bool start = true;
  for (int num : this->sequence)
  {
    for (int ii = 0; ii < this->boards.size(); ++ii)
    {
      if (start)
      {
        this->boards[ii].reset();
      }

      int res = this->boards[ii].draw(num);
      if (res > 0) {
        // std::cout()
        return res * num;
      }
    }

    if (start)
    {
      start = false;
    }
  }
  return 0;
}