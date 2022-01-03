#include <string>
#include <stdexcept>
#include <vector>
#include "./day10.h"

using namespace day10;
using std::string;
using std::vector;

Line::Line(string line)
{
  int open = 0;

  for (char ch : line)
  {
    switch (ch)
    {
    case '{':
    case '(':
    case '[':
    case '<':
      this->remaining.push_back(ch);
      break;
    case '}':
    case ')':
    case ']':
    case '>':
    {
      char prev = 'x';
      if (this->remaining.size())
      {
        prev = this->remaining.back();
      }

      if (ch == '}' && prev != '{')
      {
        this->errScore = 1197;
        return;
      }
      else if (ch == ')' && prev != '(')
      {
        this->errScore = 3;
        return;
      }
      else if (ch == ']' && prev != '[')
      {
        this->errScore = 57;
        return;
      }
      else if (ch == '>' && prev != '<')
      {
        this->errScore = 25137;
        return;
      }

      this->remaining.pop_back();
    }
    break;
    default:
      throw std::invalid_argument("Unexpected character: " + string(1, ch));
      break;
    }
  }
}

unsigned long long Line::completeLine()
{
  unsigned long long score = 0;
  while (this->remaining.size())
  {
    score *= 5;

    switch (this->remaining.back())
    {
    case '(':
      score += 1;
      break;
    case '[':
      score += 2;
      break;
    case '{':
      score += 3;
      break;
    case '<':
      score += 4;
      break;
    default:
      throw std::invalid_argument(
          "Unexpected remaining character: " + string(1, this->remaining.back()));
      break;
    }

    this->remaining.pop_back();
  }

  return score;
}
