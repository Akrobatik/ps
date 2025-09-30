// Title : Thinking Tiling 2
// Link  : https://www.acmicpc.net/problem/34567 
// Time  : 40 ms
// Memory: 12296 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1000;

constexpr bool operator==(const pair<int, int>& lhs, const pair<int, int>& rhs) {
  return lhs.first == rhs.first && lhs.second == rhs.second;
}

pair<int, int> memo[kMax + 1][kMax + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  queue<pair<int, int>> q;
  q.push({2, 2});
  q.push({3, 3});
  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();

    if (r % 2 == 0 && c + 2 <= kMax && memo[r][c + 2] == pair<int, int>{0, 0}) {
      memo[r][c + 2] = {r, c};
      q.push({r, c + 2});
    }
    if (r % 3 == 0 && c + 3 <= kMax && memo[r][c + 3] == pair<int, int>{0, 0}) {
      memo[r][c + 3] = {r, c};
      q.push({r, c + 3});
    }
    if (c % 2 == 0 && r + 2 <= kMax && memo[r + 2][c] == pair<int, int>{0, 0}) {
      memo[r + 2][c] = {r, c};
      q.push({r + 2, c});
    }
    if (c % 3 == 0 && r + 3 <= kMax && memo[r + 3][c] == pair<int, int>{0, 0}) {
      memo[r + 3][c] = {r, c};
      q.push({r + 3, c});
    }
  }

  vector<tuple<int, int, int>> arr;

  int t;
  cin >> t;
  while (t--) {
    int r, c;
    cin >> r >> c;

    if ((r != 2 || c != 2) && (r != 3 || c != 3) && memo[r][c] == pair<int, int>{0, 0}) {
      cout << "0\n";
      continue;
    }

    arr.clear();
    while (r && c) {
      auto [nr, nc] = memo[r][c];
      int dy = r - nr, dx = c - nc;
      if (dy == 2 && dx == 2) {
        arr.push_back({1, 0, 0});
      } else if (dy == 3 && dx == 3) {
        arr.push_back({2, 0, 0});
      } else if (dy == 2) {
        for (int i = 0; i < nc; i += 2) {
          arr.push_back({1, nr, i});
        }
      } else if (dy == 3) {
        for (int i = 0; i < nc; i += 3) {
          arr.push_back({2, nr, i});
        }
      } else if (dx == 2) {
        for (int i = 0; i < nr; i += 2) {
          arr.push_back({1, i, nc});
        }
      } else {
        for (int i = 0; i < nr; i += 3) {
          arr.push_back({2, i, nc});
        }
      }
      r = nr, c = nc;
    }

    cout << arr.size() << "\n";
    for (auto [type, rr, cc] : arr) {
      cout << type << " " << rr + 1 << " " << cc + 1 << "\n";
    }
  }

  return 0;
}