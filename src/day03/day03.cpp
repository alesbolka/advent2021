#include <iostream>
#include "../shared/fileReader.h"
#include "./day03.h"
#include "./diagnosticsReport.cpp"

using namespace day03;

int executeDay03Task(int task)
{
  DiagnosticsReport tool;

  if (task == 1)
  {
    auto reader = [&tool](std::string line) mutable
    {
      tool.parseReportLine(line);
    };
    readByLine("./src/day03/day03.input", reader);

    int gamma = tool.getGamma();
    int epsilon = tool.getEpsilon();
    std::cout << "Gamma: " << gamma << std::endl;
    std::cout << "Epsilon: " << epsilon << std::endl;
    std::cout << "Total: " << gamma * epsilon << std::endl;
    return 0;
  }

  auto reader = [&tool](std::string line) mutable
  {
    tool.parseReportLineV2(line);
  };
  readByLine("./src/day03/day03.input", reader);

  int oxygen = tool.findByCriteria(true);
  int co2 = tool.findByCriteria(false);
  std::cout << "Oxygen: " << oxygen << std::endl;
  std::cout << "CO2: " << co2 << std::endl;
  std::cout << "Readout: " << co2 * oxygen << std::endl;

  return 0;
}