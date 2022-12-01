#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    return 1;
  }

  std::ifstream file(argv[1]);

  std::vector<std::vector<int>> c;
  auto v = std::vector<int>();

  for (std::string line; std::getline(file, line);) {
    if (!line.empty()) {
      v.push_back(std::stoi(line));
    } else {
      c.push_back(v);
      v = std::vector<int>();
    }
  }

  std::vector<int> cc(c.size());

  std::transform(c.begin(), c.end(), cc.begin(),
                 [](auto v) { return std::reduce(v.begin(), v.end()); });

  std::sort(cc.begin(), cc.end());
  std::cout << cc.back() << std::endl;
  std::cout << std::reduce(cc.end() - 3, cc.end()) << std::endl;

  return 0;
}
