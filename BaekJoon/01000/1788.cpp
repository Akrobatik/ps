// Title : 피보나치 수의 확장
// Link  : https://www.acmicpc.net/problem/1788 
// Time  : 4 ms
// Memory: 5928 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9;

int memo[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memo[0] = 0, memo[1] = 1;
  for (int i = 2; i <= 1000000; i++) {
    memo[i] = (memo[i - 1] + memo[i - 2]) % kMod;
  }

  int n;
  cin >> n;
  if (n < 0) {
    n = -n;
    if (n & 1) {
      cout << "1\n"
           << memo[n];
    } else {
      cout << "-1\n"
           << memo[n];
    }
  } else if (n > 0) {
    cout << "1\n"
         << memo[n];
  } else {
    cout << "0\n0";
  }

  return 0;
}
