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

  switch (this->mode)
  {
  case InstructionMode::Day02Task1:
    this->commandD2T1(Submarine::identifyCommand(command), atoi(value.c_str()));
    break;
  default:
    this->commandD2T2(Submarine::identifyCommand(command), atoi(value.c_str()));
    break;
  }
}

void Submarine::commandD2T1(SubCommand command, int val)
{
  switch (command)
  {
  case SubCommand::up:
    this->depth -= val;
    break;
  case SubCommand::down:
    this->depth += val;
    break;
  case SubCommand::forward:
    this->posX += val;
    break;
  }
}

void Submarine::commandD2T2(SubCommand command, int val)
{
  switch (command)
  {
  case SubCommand::up:
    this->aim -= val;
    break;
  case SubCommand::down:
    this->aim += val;
    break;
  case SubCommand::forward:
    this->posX += val;
    this->depth += this->aim * val;
    break;
  }
}

int Submarine::getResult()
{
  return this->posX * this->depth;
}