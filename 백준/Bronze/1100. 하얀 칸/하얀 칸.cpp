#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  char m[8][8];
  for (auto& r : m) {
    for (auto& c : r) cin >> c;
  }

  int ans = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (((i + j) & 1) || m[i][j] == '.') continue;
      ++ans;
    }
  }
  cout << ans;

  return 0;
}
