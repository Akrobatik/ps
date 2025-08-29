// Title : 삼색정리
// Link  : https://www.acmicpc.net/problem/32102 
// Time  : 68 ms
// Memory: 6036 KB

#include <bits/stdc++.h>

using namespace std;

constexpr const char* kType = "RGB";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  int nm = n * m;

  pair<int, int> color[3];
  for (int i = 0; i < 3; i++) {
    int x;
    cin >> x;
    color[i] = {x, i};
  }
  sort(color, color + 3, greater<pair<int, int>>());
  swap(color[1], color[2]);

  if (color[0].first > ((nm + 1) >> 1)) {
    cout << "NO";
    return 0;
  }

  int type = 0;

  vector<string> board(n, string(m, '\0'));
  int limit = n + m - 2;
  for (int b = 0; b < 2; b++) {
    for (int i = b; i <= limit; i += 2) {
      int lb = max<int>(i - n + 1, 0);
      int ub = min<int>(i, m - 1);
      for (int x = lb; x <= ub; x++) {
        int y = i - x;
        board[y][x] = kType[color[type].second];
        if (--color[type].first == 0) ++type;
      }
    }
  }

  cout << "YES\n";
  for (auto& s : board) cout << s << "\n";

  return 0;
}
