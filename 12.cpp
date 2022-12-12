#include <fstream>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#include <fmt/core.h>
#include <fmt/ranges.h>

typedef std::pair<int, int> pos;

int solution(std::vector<std::string> data, pos start,
             std::function<bool(pos)> done,
             std::function<bool(char, char)> nogo) {

  int max_x = data[0].size() - 1;
  int max_y = data.size() - 1;

  bool visited[data.size()][data[0].size()];
  std::fill_n(&visited[0][0], sizeof(visited) / sizeof(**visited), false);

  std::queue<std::vector<pos>> q{};
  std::vector<pos> s{};

  s.push_back(start);
  q.push(s);

  bool found = false;

  while (!q.empty()) {
    auto n = q.front();
    q.pop();

    auto cur = n.back();

    // fmt::print("{}\n", fmt::join(n, ">"));
    char c = data[cur.second][cur.first];

    std::vector<pos> neighbours{
        {cur.first - 1, cur.second},
        {cur.first + 1, cur.second},
        {cur.first, cur.second - 1},
        {cur.first, cur.second + 1},
    };

    for (auto ngb : neighbours) {
      int nx = ngb.first;
      int ny = ngb.second;

      if (visited[ny][nx] || nx < 0 || nx > max_x || ny < 0 || ny > max_y)
        continue;

      char nc = data[ny][nx];

      if (nogo(nc, c))
        continue;

      auto ns = n;
      ns.push_back({nx, ny});
      q.push(ns);
      visited[ny][nx] = true;

      if (done(pos{nx, ny})) {
        found = true;
        break;
      }
    }

    if (found) break;
  }

  /*
  for (auto p: q.back()) {
    std::cout << data[p.second][p.first] << fmt::format("{} ", p);
  }
  std::cout << std::endl;
  */

  return q.back().size() - 1;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    return 1;
  }

  std::ifstream file(argv[1]);

  pos start, stop;
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

  // fmt::print("{}\n", fmt::join(data, "\n"));

  int first = solution(
      data, start, [&](pos x) { return x == stop; },
      [](char nc, char c) { return nc - 1 > c; });
  int second = solution(
      data, stop, [&](pos x) { return data[x.second][x.first] == 'a'; },
      [](char nc, char c) { return nc + 1 < c; });

  std::cout << first << std::endl;
  std::cout << second << std::endl;
}
