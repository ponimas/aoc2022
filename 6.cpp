#include <fstream>
#include <iostream>

#include <unordered_set>

const int SZ = 4;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    return 1;
  }

  std::ifstream file(argv[1]);
  std::string input;
  file >> input;

  for (int i = 0; i < input.size() - 4; i++) {
    std::unordered_set<char> v{input.begin() + i, input.begin() + i + SZ};
    if (v.size() == 4) {
      std::cout << i + SZ << std::endl;
      break;
    }

  }

}
