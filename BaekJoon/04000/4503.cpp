// Title : 구슬
// Link  : https://www.acmicpc.net/problem/4503 
// Time  : 576 ms
// Memory: 95328 KB

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

constexpr int kLen = 13;
constexpr int kMax = kLen << 1;
constexpr int kMask = (1 << kLen) - 1;
constexpr int kTable[] = {0, 4, 2, 6, 1, 5, 3, 7};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int8_t> memo(1 << kMax, INT8_MAX);
  deque<pair<int, int>> dq;

  auto Push = [&](int x, int d, bool b) {
    if (memo[x] <= d) return;
    memo[x] = d;
    if (b) {
      dq.push_back({x, d});
    } else {
      dq.push_front({x, d});
    }
  };

  auto Rot = [&](int x) {
    return ((x & 1) << (kLen - 1)) | (x >> 1);
  };

  auto Swap = [&](int l, int r) {
    int lv = l & 7, rv = r & 7;
    l ^= lv, r ^= rv;
    l |= rv, r |= lv;
    return (l << kLen) | r;
  };

  Push(kMask, 0, true);
  while (!dq.empty()) {
    auto [lr, d] = dq.front();
    dq.pop_front();

    if (memo[lr] != d) continue;

    int l = lr >> kLen, r = lr & kMask;
    Push((Rot(l) << kLen) | r, d, false);
    Push((l << kLen) | Rot(r), d, false);
    Push(Swap(l, r), d + 1, true);
  }

  string s;
  while (cin >> s) {
    int x = 0;
    for (int i = 0; i < kMax; i++) {
      if (s[i] == 'g') x |= (1 << i);
    }
    cout << (int)memo[x] << "\n";
  }

  return 0;
}
