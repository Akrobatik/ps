// Title : x와 배수와 XOR (Hard)
// Link  : https://www.acmicpc.net/problem/34407 
// Time  : 284 ms
// Memory: 3488 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int64_t x;
    cin >> x;

    if (x == 0) {
      cout << "1\n"
           << "2\n";
      continue;
    }

    while (~x & 1) x >>= 1;
    int bw = bit_width((uint32_t)x);
    int minn = 1 << bw, mask = minn - 1;

    unordered_map<int, int> memo;
    for (int b = 1; b < minn; b <<= 1) {
      unordered_map<int, int> mnxt;
      int lm = b - 1, um = mask ^ lm;

      auto Push = [&](int v) {
        int y = (x * v) & mask;
        int l = y & lm, u = y & um;
        if (l & x) return;
        if (!(x & y)) minn = min<int>(minn, v);

        if (mnxt.contains(u) && mnxt[u] <= v) return;
        mnxt[u] = v;
      };

      Push(b);
      for (auto [k, v] : memo) {
        Push(v);
        Push(v + b);
      }

      swap(memo, mnxt);
    }

    cout << "2\n"
         << minn << " " << minn + 1 << "\n";
  }

  return 0;
}