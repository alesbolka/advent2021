#include <string>
#include <stdexcept>
#include <vector>
#include "./day10.h"

using namespace day10;
using std::string;
using std::vector;

day10::Line::Line(string line)
{
  int open = 0;
  vector<char> remaining;

  for (char ch : line)
  {
    switch (ch)
    {
    case '{':
    case '(':
    case '[':
    case '<':
      remaining.push_back(ch);
      break;
    case '}':
    case ')':
    case ']':
    case '>':
    {
      char prev = 'x';
      if (remaining.size())
      {
        prev = remaining.back();
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

      remaining.pop_back();
    }
    break;
    default:
      throw std::invalid_argument("Unexpected character: " + string(1, ch));
      break;
    }
  }

  this->complete = remaining.size() == 0;
}