#include <algorithm>
#include <fstream>
#include <iostream>

#include <iterator>
#include <string>
#include <unordered_set>

int prio(char c) {
  int p = c - 96;
  if (p < 0) {
    return p + 32 + 26;
  }
  return p;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    return 1;
  }

  std::ifstream file(argv[1]);
  int sum = 0;

  for (std::string line; std::getline(file, line);) {

    int l = line.length() / 2;

    std::sort(line.begin(), line.end() - l);
    std::sort(line.begin() + l, line.end());

    std::unordered_set<char> v;

    std::set_intersection(line.begin(), line.end() - l,
                          line.begin() + l, line.end(),
                          std::inserter(v, v.begin()));
    std::cout << std::string(v.begin(), v.end()) << std::endl;
    for (char c : v) {sum += prio(c);};
  }

  std::cout << sum << std::endl;

}
