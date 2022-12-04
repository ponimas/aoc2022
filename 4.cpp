#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ranges>
#include <regex>
#include <utility>
#include <vector>

std::regex regex{R"([-,]+)"};

bool contains(int x, int y, int a, int b) {
  return (x <= a && y >= b) || (x >= a && y <= b);
}

bool overlap(int x, int y, int a, int b) {

  return (x <= a && y >= a)
    || (a <= x && b >= x);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    return 1;
  }

  std::ifstream file(argv[1]);
  int cnt_one = 0;
  int cnt_two = 0;


  for (std::string line; std::getline(file, line);) {
    std::sregex_token_iterator it{line.begin(), line.end(), regex, -1};
    std::vector<std::string> pos{it, {}};

    std::vector<int> posi;
    std::ranges::transform(pos, std::back_inserter(posi),
                           [](auto s) { return std::stoi(s); });

    if (contains(posi[0], posi[1], posi[2], posi[3])) {
      cnt_one++;

      std::cout << "contains: ";
      // before c++20
      // std::copy(pos.begin(), pos.end(),
      //           std::ostream_iterator<std::string>(std::cout, " "));
      // c++20
      std::ranges::copy(pos,
                        std::ostream_iterator<std::string>(std::cout, " "));
      std::cout << std::endl;

    }

    if (overlap(posi[0], posi[1], posi[2], posi[3])) {
      cnt_two++;

      std::cout << "overlap: ";
      std::ranges::copy(pos,
                        std::ostream_iterator<std::string>(std::cout, " "));
      std::cout << std::endl;
    }
  }

  std::cout << cnt_one << std::endl;
  std::cout << cnt_two << std::endl;
}
