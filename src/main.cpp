#include <iostream>
#include <exception>
#include "./day01/day01.cpp"
#include "./day02/day02.cpp"
#include "./day03/day03.cpp"
#include "./shared/fileReader.cpp"

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
    return 0;
  default:
    cout << "Invalid task " << task << " specified for day " << day << endl;
    return 1;
  }
}