#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <vector>

template <typename lineReader>
void readByLine(std::string filepath, lineReader reader);

std::vector<int> readArrayInt(std::string filepath);
std::vector<std::string> readArrayString(std::string filepath);

#endif