#include <iostream>
#include <vector>

int main() {
  int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x = 0, y = 0;
  std::cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
  std::vector<char> result;
  if (y > y2) result.push_back('N');
  if (y < y1) result.push_back('S');
  if (x < x1) result.push_back('W');
  if (x > x2) result.push_back('E');

  for (size_t i = 0; i < result.size(); i++) {
    std::cout << result[i];
  }
  
  return 0;
}


