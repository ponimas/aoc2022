#include <fstream>
#include <iostream>

#include <fmt/core.h>
#include <fmt/ranges.h>
#include <string>
#include <utility>
#include <vector>

typedef std::pair<long, long> point;

int KEY = 811589153;

void mix(std::vector<point> &data) {
  for(int i = 0; i < data.size(); ++i) {
    int pos = 0;
    for (int y = 0; y < data.size(); ++y) {
      if (data[y].first == i) {
        pos = y;
        break;
      }
    }

    auto x = data[pos];
    data.erase(data.begin() + pos);

    int shift = std::div(x.second + pos, data.size()).rem;

    // std::cout << "shift " << x.first << " " << x.second << " " << shift << std::endl;

    if (shift > 0)
      data.insert(data.begin() + shift, x);
    else
      data.insert(data.end() + shift, x);

    // for (auto l: data)
    //   std::cout << l.second << " ";
    // std::cout << std::endl;
  }
}

void result(std::vector<point> &data) {
    int pos = 0;
  for(int i =0; i < data.size(); ++i ) {
    if (data[i].second == 0) {
      pos = i;
      break;
    }
  }

  int s =0;
  for (int x: {1000, 2000, 3000}){
    int z = std::div(x + pos, data.size()).rem;
    // std::cout <<  data[z].second << std::endl;
    s += data[z].second;
  }
  std::cout <<  s << std::endl;
}


int main(int argc, char *argv[]) {

  // std::cout << "Long Int Max " << std::numeric_limits<long int>::max() << std::endl;
  // std::cout << "Long Long Int Max " << std::numeric_limits<long long int>::max() << std::endl;

  if (argc < 2) {
    return 1;
  }

  std::vector<point> data{};
  std::ifstream file(argv[1]);

  int cnt = 0;
  for (std::string line; std::getline(file, line);) {
    if (line.empty()) break;

    auto x = std::stoi(line);
    data.push_back({cnt++, x});
  }


  auto f = data;
  mix(f);
  result(f);


  auto s = data;

  for (int i=0; i < s.size(); ++i) {
    s[i] = {s[i].first, s[i].second * KEY};
  }
  
  // for (auto l: data)
  //   std::cout << l.first << " " << l.second << std::endl;

  // for (auto l: s)
  //   std::cout << l.first << " " << l.second << std::endl;

  for (int i=0; i < 10; ++i) {
    mix(s);
  }

  result(s);
}
