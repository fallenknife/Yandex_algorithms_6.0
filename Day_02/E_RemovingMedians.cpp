#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n = 0, left = 0, right = 0;
  ;
  cin >> n;
  vector<int> numbers(n);
  vector<int> result;

  for (int i = 0; i < n; i++) {
    cin >> numbers[i];
  }
  sort(numbers.begin(), numbers.end());
  left = numbers.size() / 2 - 1;
  right = numbers.size() / 2;
  if (numbers.size() % 2 == 0) {
    while (left >= 0 && right < numbers.size()) {
      if (numbers[left] >= numbers[right]) {
        cout << numbers[right] << " " << numbers[left] << " ";
      } else {
        cout << numbers[left] << " " << numbers[right] << " ";
      }
      left--;
      right++;
    }

  } else {
    cout << numbers[numbers.size() / 2] << " ";
    right++;
    while (left >= 0 && right < numbers.size()) {
      if (numbers[left] >= numbers[right]) {
        cout << numbers[right] << " " << numbers[left] << " ";
      } else {
        cout << numbers[left] << " " << numbers[right] << " ";
      }
      left--;
      right++;
    }

    return 0;
  }
}
