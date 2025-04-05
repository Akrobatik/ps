// Title : 스도쿠 채점
// Link  : https://www.acmicpc.net/problem/9291
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  for (int ci = 1; ci <= t; ci++) {
    int sub_masks[9] = {};
    int row_masks[9] = {};
    int col_masks[9] = {};
    for (int y = 0; y < 9; y++) {
      for (int x = 0; x < 9; x++) {
        int v;
        cin >> v;
        int s = y - y % 3 + x / 3;
        int m = 1 << (v - 1);
        sub_masks[s] |= m;
        row_masks[y] |= m;
        col_masks[x] |= m;
      }
    }

    bool ok = true;
    for (int i = 0; i < 9; i++) {
      constexpr int kMask = (1 << 9) - 1;
      if ((sub_masks[i] ^ kMask) || (row_masks[i] ^ kMask) || (col_masks[i] ^ kMask)) {
        ok = false;
        break;
      }
    }

    cout << "Case " << ci << ": " << (ok ? "CORRECT\n" : "INCORRECT\n");
  }

  return 0;
}
