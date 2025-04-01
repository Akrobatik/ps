#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {0, 1}, {1, 0}, {1, 1}, {-1, 1}};

constexpr bool kMatch[] = {false, true, true, true, true, true, false};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  char m[30][30];
  memset(m, 0, sizeof(m));
  for (int i = 5; i < 24; i++) {
    for (int j = 5; j < 24; j++) {
      cin >> m[i][j];
    }
  }

  auto Check = [&](int y, int x) {
    if (m[y][x] == '0') return false;
    char c = m[y][x];
    for (auto [dy, dx] : kDelta) {
      bool ok = true;
      for (int i = -1; i <= 5; i++) {
        if ((m[y + dy * i][x + dx * i] == c) == kMatch[i + 1]) continue;
        ok = false;
        break;
      }
      if (ok) return true;
    }
    return false;
  };

  for (int i = 5; i < 24; i++) {
    for (int j = 5; j < 24; j++) {
      if (Check(i, j)) {
        cout << m[i][j] << "\n"
             << i - 4 << " " << j - 4;
        return 0;
      }
    }
  }
  cout << "0";

  return 0;
}
