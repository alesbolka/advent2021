#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
// #include <string>

template<typename lineReader>
void readByLine (std::string filepath, lineReader reader)
{
  std::string line;
  std::ifstream fileStream(filepath);
  while (std::getline(fileStream, line))
  {
    reader(line);
  }
}

std::vector<int> readArrayInt(std::string filepath)
{
  // Can't get the reader to work with the implementation above, to look at later
  std::vector<int> result;
  // auto mapper = [result](std::string line) mutable
  // {
  //   result.push_back(std::atoi(line.c_str()));
  //   std::cout << result.size() << std::endl;
  // };
  // readByLine(filepath, mapper);
  std::string line;
  std::ifstream fileStream(filepath);
  while (std::getline(fileStream, line))
  {
    result.push_back(std::atoi(line.c_str()));
  }
  std::cout << "done read: " << result.size() << std::endl;
  return result;
}