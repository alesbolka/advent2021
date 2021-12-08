#include <sstream>
#include <map>
#include "./day04.h"

using namespace day04;

void BingoBoard::parseLine(string line)
{
  std::stringstream stream(line);
  int rowSize = -1;

  for (int ii; stream >> ii;)
  {
    if (this->numbers.count(ii) != 0)
    {
      throw std::invalid_argument("Found a number that repeats for a board: " + std::to_string(ii));
    }
    this->numbers[ii] = std::array<int, 2>{this->rows, ++rowSize};
    this->totalSum += ii;

    // Skip empty characters, there might be more than 1
    while (stream.peek() == ' ')
    {
      stream.ignore();
    }
  }

  if (this->cols == -1)
  {
    this->cols = ++rowSize;
  }
  else if (this->cols != ++rowSize)
  {
    throw std::invalid_argument("Column count mismatch");
  }

  ++this->rows;
}

int BingoBoard::draw(int number)
{
  if (this->numbers.count(number) == 0)
  {
    return 0;
  }

  // should always exist due to the first check
  if (!this->gameNumbers[number])
  {
    return false;
  }

  std::array<int, 2> coords = this->numbers[number];
  this->gameNumbers[number] = false;
  this->gameSum -= number;

  if (++this->colHits[coords[0]] == this->cols || ++this->rowHits[coords[1]] == this->rows)
  {
    this->hasWon = true;
    return this->gameSum;
  }

  return 0;
}

void BingoBoard::reset()
{
  this->hasWon = false;
  this->rowHits = vector<int>(this->rows);
  this->colHits = vector<int>(this->cols);
  this->gameNumbers = std::map<int, bool>{};
  for (auto const &it : this->numbers)
  {
    this->gameNumbers[it.first] = true;
  }

  this->gameSum = this->totalSum;
}