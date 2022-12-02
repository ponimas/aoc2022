#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>

#include "matchit.h"

int match_one(std::string cs) {
  using namespace matchit;

  return match(cs[0], cs[2])(
      pattern | ds('A', 'X') = [] { return 3 + 1; },
      pattern | ds('B', 'X') = [] { return 0 + 1; },
      pattern | ds('C', 'X') = [] { return 6 + 1; },

      pattern | ds('A', 'Y') = [] { return 6 + 2; },
      pattern | ds('B', 'Y') = [] { return 3 + 2; },
      pattern | ds('C', 'Y') = [] { return 0 + 2; },

      pattern | ds('A', 'Z') = [] { return 0 + 3; },
      pattern | ds('B', 'Z') = [] { return 6 + 3; },
      pattern | ds('C', 'Z') = [] { return 3 + 3; });
}

int match_two(std::string cs) {
  using namespace matchit;

  return match(cs[0], cs[2])(
      pattern | ds('A', 'X') = [] { return 0 + 3; },
      pattern | ds('B', 'X') = [] { return 0 + 1; },
      pattern | ds('C', 'X') = [] { return 0 + 2; },

      pattern | ds('A', 'Y') = [] { return 3 + 1; },
      pattern | ds('B', 'Y') = [] { return 3 + 2; },
      pattern | ds('C', 'Y') = [] { return 3 + 3; },

      pattern | ds('A', 'Z') = [] { return 6 + 2; },
      pattern | ds('B', 'Z') = [] { return 6 + 3; },
      pattern | ds('C', 'Z') = [] { return 6 + 1; });
}


int main(int argc, char *argv[]) {
  if (argc < 2) {
    return 1;
  }

  std::ifstream file(argv[1]);
  int score_one = 0, score_two = 0;

  for (std::string line; std::getline(file, line);) {
    score_one += match_one(line);
    score_two += match_two(line);
  }

  std::cout << score_one << std::endl;
  std::cout << score_two << std::endl;
}
