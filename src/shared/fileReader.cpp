#include <fstream>
#include <sstream>
#include <vector>
#include <string>

template <typename lineReader>
void readByLine(std::string filepath, lineReader reader)
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
  std::vector<int> result;
  auto mapper = [&result](std::string line) mutable
  {
    result.push_back(std::atoi(line.c_str()));
  };
  readByLine(filepath, mapper);

  return result;
}