#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long N = 0, R = 0, i = 0, j = 0, count = 0;
  cin >> N >> R;
  vector<long long> numbers(N);
  for (long long &h : numbers) {
    cin >> h;
  }

  while (j < N && i < N - 1) {
    if (numbers[j] - numbers[i] <= R) {
      j++;
    } else {
      count += N - j;
      i++;
    }
  }
  cout << count;
  return 0;
}