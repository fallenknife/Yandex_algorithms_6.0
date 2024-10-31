#include <iostream>
#define A a[0]
#define B a[1]
#define C a[2]
#define D a[3]

long long min(long long a, long long b)
{
  if (a == b) {
    return a;
  }
  else {
    return (a > b ? b : a);
  }
}


int main()
{
  long long a[4] = { 0,0,0,0 };
  for (int i = 0; i < 4; i++)
  {
    std::cin >> a[i];
  }

  if (A && B && C && D)
  {
    long long  max_AB = (A >= B ? A : B);
    long long  max_CD = (C >= D ? C : D);

    if (((A + C) > (B + D)) && ((B + D) < min(max_AB, max_CD))) {
      if (max_CD == max_AB) {
        std::cout << min(A, B) + 1 << " " << min(C, D) + 1;
      }
      else {
        std::cout << B + 1 << " " << D + 1;
      }
    }
    else if (((B + D) > (A + C)) && ((A + C) < min(max_AB, max_CD))) {
      if (max_CD == max_AB) {
        std::cout << min(A, B) + 1 << " " << min(C, D) + 1;
      }
      else {
        std::cout << A + 1 << " " << C + 1;
      }

    }
    else if (max_AB <= max_CD) {
      std::cout << max_AB + 1 << " 1";
    }
    else {
      std::cout << "1 " << max_CD + 1;
    }
  }
  else {
    if (A == 0) {
      std::cout << "1 " << C + 1;
    }
    else if (C == 0) {
      std::cout << A + 1 << " 1";
    }
    else if (B == 0) {
      std::cout << "1 " << D + 1;
    }
    else if (D == 0) {
      std::cout << B + 1 << " 1";
    }
  }
  return 0;
}
