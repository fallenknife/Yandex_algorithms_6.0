#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n = 0, k = 0, i = 0, j = 0, result = 0;
  cin >> n >> k;

  vector<int> numbers(n);

  for (int &i : numbers) {
    cin >> i;
  }
  sort(numbers.begin(), numbers.end());
  while (i < numbers.size()) {
    if (numbers[i] <= numbers[j] + k) {
      i++;
    } else {
      result = result >= i - j ? result : i - j;
      j++;
    }
  }
  cout << (result >= i - j ? result : i - j);
  return 0;
}
