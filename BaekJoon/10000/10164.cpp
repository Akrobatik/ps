// Title : 격자상의 경로
// Link  : https://www.acmicpc.net/problem/10164 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int64_t Combination(int64_t n, int64_t r) {
  int64_t x = 1;
  for (int64_t i = 0; i < r; i++) {
    x = x * (n - i) / (i + 1);
  }
  return x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, m, k;
  cin >> n >> m >> k;

  if (k == 0) {
    cout << Combination(n + m - 2, m - 1);
  } else {
    int64_t y = (k - 1) / m + 1;
    int64_t x = (k - 1) % m + 1;

    int64_t a = Combination(y + x - 2, x - 1);
    y = n - y + 1, x = m - x + 1;
    int64_t b = Combination(y + x - 2, x - 1);

    cout << a * b;
  }

  return 0;
}
