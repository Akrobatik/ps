// Title : x와 배수와 XOR (Hard)
// Link  : https://www.acmicpc.net/problem/34407 
// Time  : 124 ms
// Memory: 2468 KB

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

    vector<int> memo;
    for (int b = 2; b < minn; b <<= 1) {
      vector<int> mnxt;
      int lm = b - 1, um = mask ^ lm;

      auto Push = [&](int v) {
        int y = (x * v) & mask;
        int l = y & lm;
        if (l & x) return;
        if (!(x & y)) minn = min<int>(minn, v);
        mnxt.push_back(v);
      };

      Push(b);
      for (auto e : memo) {
        Push(e);
        Push(e + b);
      }

      sort(mnxt.begin(), mnxt.end(), [&](int lhs, int rhs) {
        int lu = (x * lhs) & um;
        int ru = (x * rhs) & um;
        if (lu == ru) return lhs < rhs;
        return lu < ru;
      });

      auto it = unique(mnxt.begin(), mnxt.end(), [&](int lhs, int rhs) {
        int lu = (x * lhs) & um;
        int ru = (x * rhs) & um;
        return lu == ru;
      });
      mnxt.erase(it, mnxt.end());

      swap(memo, mnxt);
    }

    cout << "2\n"
         << minn << " " << minn + 1 << "\n";
  }

  return 0;
}