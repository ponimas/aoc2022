#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>

#include <fmt/core.h>
#include <fmt/ranges.h>


int main(int argc, char *argv[]) {
  if (argc < 2) {
    return 1;
  }

  std::ifstream file(argv[1]);

  std::pair<int,int> start, stop;

  int y = 0;
  std::vector<std::string> data;

  for (std::string line; std::getline(file, line);) {
    for (int x = 0; x < line.size(); ++x) {
      if (line[x] == 'S') {
        start = {x, y};
        line[x] = 'a';
      } else if (line[x] == 'E') {
        stop = {x, y};
        line[x] = 'z';
      }
    }

    data.push_back(line);
    y++;
  }

  fmt::print("{}\n", fmt::join(data, "\n"));
  int max_x = data[0].size() - 1;
  int max_y = data.size() - 1;

  bool visited[data.size()][data[0].size()];
  std::fill_n(&visited[0][0], sizeof(visited) / sizeof(**visited), false);

  std::queue<std::vector<std::pair<int, int>>> q{};
  std::vector<std::pair<int, int>> s{};

  s.push_back(start);
  q.push(s);

  bool found = false;

  while(!q.empty()) {
    auto n = q.front();
    q.pop();

    auto cur = n.back();
    // fmt::print("{}\n", fmt::join(n, ">"));
    char c = data[cur.second][cur.first];

    std::vector<std::pair<int,int>> neighbours {
      {cur.first - 1, cur.second},
      {cur.first + 1, cur.second},
      {cur.first, cur.second - 1},
      {cur.first, cur.second + 1},
    };

    for (auto ngb : neighbours) {
      int nx = ngb.first;
      int ny = ngb.second;

      if (found)
        break;
      if (visited[ny][nx])
        continue;
      if (nx < 0 || nx > max_x || ny < 0 || ny > max_y)
        continue;

      char nc = data[ny][nx];
      if (nc - 1 > c)
        continue;

      auto ns = n;
      ns.push_back({nx, ny});
      q.push(ns);
      visited[ny][nx] = true;
      if (stop.first == nx && stop.second == ny)
        found = true;
    }
    if (found)
      break;
  }

  auto solve = q.back();

  /*
  for (auto p: solve) {
    std::cout << data[p.second][p.first] << fmt::format("{} ", p);
  }
  std::cout << std::endl;
  */


  std::cout << q.back().size() - 1 << std::endl;
}
