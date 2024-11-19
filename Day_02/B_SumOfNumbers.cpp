#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N = 0, K = 0;
  cin >> N >> K;
  vector<int> numbers(N);
  for (int &h : numbers) {
    cin >> h;
  }

  int left = 0, right = 0;
  long long sum = 0;
  int counter = 0;

  while (right <= N) {
    if (sum == K) {
      counter++;
      sum -= numbers[left++];
    } else if (sum < K) {
      sum += numbers[right++];
    } else {
      sum -= numbers[left++];
    }
  }
  
  cout << counter;
  return 0;
}
