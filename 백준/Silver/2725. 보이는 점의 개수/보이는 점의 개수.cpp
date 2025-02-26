#include <bits/stdc++.h>

using namespace std;

int memo[1001];

int GCD(int a, int b) {
  while (b) a %= b, swap(a, b);
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memo[1] = 3;
  for (int i = 2; i <= 1000; i++) {
    int cnt = 0;
    for (int j = 1; j < i; j++) cnt += GCD(i, j) == 1;
    memo[i] = memo[i - 1] + (cnt << 1);
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << memo[n] << "\n";
  }

  return 0;
}
