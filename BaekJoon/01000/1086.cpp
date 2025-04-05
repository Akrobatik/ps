// Title : 박성원
// Link  : https://www.acmicpc.net/problem/1086 
// Time  : 100 ms
// Memory: 27624 KB

#include <bits/stdc++.h>

using namespace std;

int64_t memo[1 << 15][100];
int remains[15];
int shifts[15];

int64_t GCD(int64_t a, int64_t b) {
  int64_t c = a % b;
  if (c == 0) return b;
  return GCD(b, c);
}

int64_t Factorial(int n) {
  int64_t res = 1;
  for (int i = 2; i <= n; i++) res *= i;
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<string> nums(n);
  for (int i = 0; i < n; i++) cin >> nums[i];
  int k;
  cin >> k;
  for (int i = 0; i < n; i++) {
    shifts[i] = 1 % k;
    for (auto it = nums[i].begin(); it != nums[i].end(); ++it) {
      remains[i] = (remains[i] * 10 + (*it - '0')) % k;
      shifts[i] = (shifts[i] * 10) % k;
    }
  }

  memo[0][0] = 1;
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) continue;
      for (int l = 0; l < k; l++) {
        int rem = (remains[j] + shifts[j] * l) % k;
        memo[i | (1 << j)][rem] += memo[i][l];
      }
    }
  }

  int64_t sum = memo[(1 << n) - 1][0];
  int64_t total = Factorial(n);
  if (sum == 0) {
    cout << "0/1";
  } else if (total == sum) {
    cout << "1/1";
  } else {
    auto gcd = GCD(sum, total);
    cout << sum / gcd << "/" << total / gcd;
  }

  return 0;
}
