// Title : 토너먼트
// Link  : https://www.acmicpc.net/problem/34227 
// Time  : 132 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto Count = [](uint64_t x) {
    int cnt = 0;
    while (x > 1) {
      cnt += x & 1;
      x = (x + 1) >> 1;
    }
    return cnt;
  };

  int t;
  cin >> t;
  while (t--) {
    uint64_t l, r;
    cin >> l >> r;

    if (bit_width(l) != bit_width(r)) {
      cout << "0\n";
      continue;
    }

    int minn = Count(l);
    while ((l += l & (-l)) <= r) {
      minn = min<int>(minn, Count(l));
    }
    cout << minn << "\n";
  }

  return 0;
}
