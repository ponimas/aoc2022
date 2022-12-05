#include <algorithm>
#include <fstream>
#include <iostream>
#include <regex>
#include <deque>
#include <string>
#include <vector>


std::regex rx_space{R"(\s+)"};

int main(int argc, char *argv[]) {
  if (argc < 2) {
    return 1;
  }

  std::ifstream file(argv[1]);

  std::vector<std::string> data;
  std::vector<std::string> commands;

  for (std::string line; std::getline(file, line);) {
    if (line.empty()) {
      break;
    }
    data.push_back(line);
  }

  auto nums = data.back();
  data.pop_back();

  std::sregex_token_iterator it{nums.begin(), nums.end(), rx_space, -1};
  std::vector<std::string> splitted{it, {}};

  int col_num = std::stoi(splitted.back());
  std::vector<std::deque<char>> crates(col_num);

  for (auto line: data) {
    auto d = crates.begin();
    for (int i = 1; i < line.size(); i += 4) {
      auto crate = line[i];
      if(std::isdigit(crate)) break;
      if (crate != ' ') {
        d->push_back(crate);
      }
      d++;
    }
  }

  auto crates_2 = crates;

  for (std::string line; std::getline(file, line);) {
    std::sregex_token_iterator it{line.begin(), line.end(), rx_space, -1};
    std::vector<std::string> splitted{it, {}};

    int n = std::stoi(splitted[1]);
    int i = std::stoi(splitted[3]) - 1;
    int j = std::stoi(splitted[5]) - 1;

    std::stack<char> tmp;

    for (int k = 0; k < n; ++k) {
      crates[j].push_front(crates[i].front());
      crates[i].pop_front();

      tmp.push(crates_2[i].front());
      crates_2[i].pop_front();
    }


    for (int k = 0; k < n; ++k) {
      crates_2[j].push_front(tmp.top());
      tmp.pop();
    }


  }

  for(auto c: crates) {
    std::cout << c.front();
  }
  std::cout << std::endl;

  for(auto c: crates_2) {
    std::cout << c.front();
  }
  std::cout << std::endl;
}
