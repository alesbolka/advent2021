#include <iostream>
#include <exception>
#include "./day01/day01.cpp"
#include "./day02/day02.cpp"
#include "./day03/day03.cpp"
#include "./day04/day04.cpp"
#include "./day05/day05.cpp"
#include "./day06/day06.cpp"
#include "./day07/day07.cpp"
#include "./day08/day08.cpp"
#include "./day09/day09.cpp"
#include "./day10/day10.cpp"
#include "./day11/day11.cpp"
#include "./day12/day12.cpp"
#include "./day13/day13.cpp"
#include "./shared/fileReader.cpp"
#include "./shared/stringHelpers.cpp"

using namespace std;

int main(int argc, char **argv)
{
  if (argc != 3)
  {
    cout << "Expected 2 arguments\n";
    cout << "Use: advent2021 <day: int> <task of day: int>\n";
    cout << "Example: advent2021 1 1\n";
    return 1;
  }

  int day, task;
  try
  {
    day = stoi(argv[1]);
  }
  catch (exception &e)
  {
    cout << "Invalid value for day: " << argv[1] << endl;
    cout << e.what() << endl;
    return 1;
  }

  try
  {
    task = stoi(argv[2]);
  }
  catch (exception &e)
  {
    cout << "Invalid value for task: " << argv[2] << endl;
    cout << e.what() << endl;
    return 1;
  }

  switch (day)
  {
  case 1:
    return executeDay01Task(task);
  case 2:
    return executeDay02Task(task);
  case 3:
    return executeDay03Task(task);
  case 4:
    return executeDay04Task(task);
  case 5:
    return day05::executeTask(task);
  case 6:
    return day06::executeTask(task);
  case 7:
    return day07::executeTask(task);
  case 8:
    return day08::executeTask(task);
  case 9:
    return day09::executeTask(task);
  case 10:
    return day10::executeTask(task);
  case 11:
    return day11::executeTask(task);
  case 12:
    return day12::executeTask(task);
  case 13:
    return day13::executeTask(task);
  default:
    cout << "Invalid task " << task << " specified for day " << day << endl;
    return 1;
  }
}