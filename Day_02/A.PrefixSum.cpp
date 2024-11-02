#include <iostream>
#include <vector>

int main() {
  int a = 0, sum = 0;
  std::vector<int> array;
  std::cin >> a;

  for (int i = 0; i < a; i++) {
    int temp = 0;
    std::cin >> temp;
    array.push_back(temp);
  }
  for (int i = 0; i < a; i++) {
    sum += array[i];
    std::cout << sum;
    if (i != a - 1) {
      std::cout << " ";
    }
  }
}