// Title : 추진기
// Link  : https://www.acmicpc.net/problem/34930 
// Time  : 24 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;

    int64_t acc = 0;

    auto Push = [&](int64_t x) {
      if (acc > 0) x = -x;
      acc += x;
      cout << x << " ";
    };

    int64_t bnd = max<int>(l, (r + 1) >> 1);
    Push(bnd);

    for (int i = r; i >= l; i--) {
      if (i == bnd) continue;
      Push(i);
    }
    cout << "\n";
  }

  return 0;
}