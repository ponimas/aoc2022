#include <algorithm>
#include <fstream>
#include <iostream>

#include <iterator>
#include <string>
#include <unordered_set>
#include <vector>

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
  int sum_one = 0;
  int sum_two = 0;


  std::vector<std::string> data;

  for (std::string line; std::getline(file, line);) {

    auto line_copy = std::string(line);
    std::ranges::sort(line_copy);
    data.push_back(line_copy);

    int l = line.length() / 2;

    std::sort(line.begin(), line.end() - l);
    std::sort(line.begin() + l, line.end());

    std::unordered_set<char> v;

    std::set_intersection(line.begin(), line.end() - l,
                          line.begin() + l, line.end(),
                          std::inserter(v, v.begin()));

    for (char c : v) {sum_one += prio(c);};
  }

  for (int i = 0; i < data.size(); i += 3) {

    std::unordered_set<char> a;
    std::unordered_set<char> b;

    auto x = data[i];
    auto y = data[i+1];
    auto z = data[i+2];


    std::set_intersection(x.begin(), x.end(),
                          y.begin(), y.end(),
                          std::inserter(a, a.begin()));
    for (char c: z) {
      if (a.contains(c)) {
        sum_two += prio(c);
        break;
      };
    }
  }
  
  std::cout << sum_one << std::endl;
  std::cout << sum_two << std::endl;

}
