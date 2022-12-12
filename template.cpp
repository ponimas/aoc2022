#include <fstream>
#include <iostream>

#include <fmt/core.h>
#include <fmt/ranges.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    return 1;
  }

  std::ifstream file(argv[1]);

  for (std::string line; std::getline(file, line);) {

  }
}
