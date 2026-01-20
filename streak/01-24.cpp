// https://www.acmicpc.net/problem/35153

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e6;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  cin >> n;

  auto F = [&](int64_t x) -> pair<int64_t, int64_t> {
    int64_t y = n + x * x;
    for (int64_t i = max<int64_t>(x, 1); i * i <= y; i++) {
      if (y % i) continue;
      int64_t a = x, b = i - x, c = y / i - x;
      if (a + b + c + 4 <= kMax) return {i, y / i};
    }
    return {0, 0};
  };

  int64_t a, b, c;
  for (int64_t i = 0;; i++) {
    auto [x, y] = F(i);
    if (x == 0 && y == 0) continue;
    a = i, b = x - i, c = y - i;
    break;
  }

  int idx = 4;
  int64_t val[3] = {a, b, c};

  cout << a + b + c + 4 << "\n"
       << "1 2\n"
       << "1 3\n"
       << "1 4\n";
  for (int i = 0; i < 3; i++) {
    int64_t x = val[i];
    while (x--) {
      cout << i + 2 << " " << ++idx << "\n";
    }
  }

  return 0;
}