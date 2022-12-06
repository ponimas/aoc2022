#include <fstream>
#include <iostream>

#include <unordered_set>

const int PKT_SZ = 4;
const int MSG_SZ = 14;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    return 1;
  }

  std::ifstream file(argv[1]);
  std::string input;
  file >> input;

  for (int i = 0; i < input.size() - PKT_SZ; i++) {

    std::unordered_set<char> v{input.begin() + i, input.begin() + i + PKT_SZ};

    if (v.size() == 4) {
      std::cout << i + PKT_SZ << std::endl;
      break;
    }
  }

  for (int i = 0; i < input.size() - MSG_SZ; i++) {

    std::unordered_set<char> v{input.begin() + i, input.begin() + i + MSG_SZ};

    if (v.size() == MSG_SZ) {
      std::cout << i + MSG_SZ << std::endl;
      break;
    }
  }


}
