#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include "./day02.h"

using namespace day02;
using std::string;

SubCommand Submarine::identifyCommand(string command)
{
  if (command == "forward")
  {
    return SubCommand::forward;
  }
  else if (command == "up")
  {
    return SubCommand::up;
  }
  else if (command == "down")
  {
    return SubCommand::down;
  }
  else
  {
    throw invalid_argument("Invalid sub command: " + command);
  }
};

void Submarine::command(string instruction)
{
  std::istringstream iss(instruction);
  string command;
  string value;
  iss >> command;
  iss >> value;

  switch (Submarine::identifyCommand(command))
  {
  case SubCommand::up:
    this->depth -= atoi(value.c_str());
    break;
  case SubCommand::down:
    this->depth += atoi(value.c_str());
    break;
  case SubCommand::forward:
    this->posX += atoi(value.c_str());
    break;
  default:
    throw invalid_argument("Invalid sub command: " + instruction);
    break;
  }
}

int Submarine::getResult()
{
  return this->posX * this->depth;
}