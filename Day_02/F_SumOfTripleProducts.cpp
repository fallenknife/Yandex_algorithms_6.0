#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long const mod = 1000000000 + 7;
  int n = 0;
  cin >> n;
  vector<long long> numbers(n);
  for (long long &a : numbers) cin >> a;
  vector<long long> previous(n);
  previous[0] = numbers[0];

  for (int i = 1; i < n; ++i) {
    previous[i] = (previous[i - 1] % mod + numbers[i] + mod) % mod;
  }
  long long sum = 0;

  for (int i = 1; i < n - 1; i++) {
    long long left =
        (mod +
         ((numbers[i] % mod) * (previous[n - 1] - previous[i]) % mod) % mod) %
        mod;
    left = (((previous[i - 1] % mod) * (left % mod)) % mod + mod) % mod;
    sum = (mod + sum + left) % mod;
  }
  cout << sum % mod;
  return 0;
}