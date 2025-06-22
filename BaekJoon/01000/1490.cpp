// Title : 자리수로 나누기
// Link  : https://www.acmicpc.net/problem/1490 
// Time  : 0 ms
// Memory: 2288 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  cin >> n;

  vector<int> digits;
  for (auto y = n; y; y /= 10) {
    auto z = y % 10;
    if (z) digits.push_back(z);
  }

  sort(digits.begin(), digits.end());
  digits.erase(unique(digits.begin(), digits.end()), digits.end());

  queue<int64_t> q;
  q.push(n);
  for (;;) {
    auto x = q.front();
    q.pop();

    bool ok = true;
    for (auto d : digits) {
      if (x % d != 0) {
        ok = false;
        break;
      }
    }

    if (ok) {
      cout << x;
      return 0;
    }

    x *= 10;
    for (int i = 0; i <= 9; i++) {
      q.push(x + i);
    }
  }

  return 0;
}
