// Title : 2 Keys Keyboard
// Link  : https://www.acmicpc.net/problem/34744 
// Time  : 36 ms
// Memory: 5928 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e6;

int memo[kMax + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(memo, 0x7f, sizeof(memo));
  memo[1] = 0;

  for (int i = 1; i <= kMax; i++) {
    int x = memo[i] + 1;
    for (int j = i << 1; j <= kMax; j += i) {
      memo[j] = min<int>(memo[j], ++x);
    }
  }

  int n;
  cin >> n;
  cout << memo[n];

  return 0;
}