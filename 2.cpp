#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, int> match_one{
    {"A X", 3 + 1}, {"B X", 3 + 1}, {"C X", 3 + 1},
    {"A Y", 6 + 2}, {"B Y", 3 + 2}, {"C Y", 0 + 2},
    {"A Z", 0 + 3}, {"B Z", 6 + 3}, {"C Z", 3 + 3}};

std::unordered_map<std::string, int> match_two{
    {"A X", 0 + 3}, {"B X", 0 + 1}, {"C X", 0 + 2},
    {"A Y", 3 + 1}, {"B Y", 3 + 2}, {"C Y", 3 + 3},
    {"A Z", 6 + 2}, {"B Z", 6 + 3}, {"C Z", 6 + 1}};

int main(int argc, char *argv[]) {
  if (argc < 2) {
    return 1;
  }

  std::ifstream file(argv[1]);
  int score_one = 0, score_two = 0;

  for (std::string line; std::getline(file, line);) {
    score_one += match_one[line];
    score_two += match_two[line];
  }

  std::cout << score_one << std::endl;
  std::cout << score_two << std::endl;
}
