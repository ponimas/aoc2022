#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ranges>
#include <regex>


std::regex regex{R"([-,]+)"}; // split on space and comma

int main(int argc, char *argv[]) {
  if (argc < 2) {
    return 1;
  }

  std::ifstream file(argv[1]);
  int cnt = 0;

  for (std::string line; std::getline(file, line);) {
    std::sregex_token_iterator it{line.begin(), line.end(), regex, -1};
    std::vector<std::string> pos{it, {}};

    std::vector<int> posi;
    std::ranges::transform(pos, std::back_inserter(posi),
                           [](auto s) { return std::stoi(s); });

    if ((posi[0] <= posi[2] && posi[1] >= posi[3]) ||
        (posi[2] <= posi[0] && posi[3] >= posi[1])) {

      cnt++;
      // before c++20
      // std::copy(pos.begin(), pos.end(),
      //           std::ostream_iterator<std::string>(std::cout, " "));
      // c++20
      std::ranges::copy(pos, std::ostream_iterator<std::string>(std::cout, " "));
      std::cout << std::endl;
      }
  }

  std::cout<< cnt << std::endl;
}
