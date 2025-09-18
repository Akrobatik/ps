// Title : 쿠키크루
// Link  : https://www.acmicpc.net/problem/22939 
// Time  : 0 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

constexpr const char* kStr[4] = {
    "Assassin", "Healer", "Mage", "Tanker"};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<string> board(n);
  for (auto& s : board) cin >> s;

  int sy, sx, ty, tx;
  vector<pair<int, int>> arr[4];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      switch (board[i][j]) {
        case 'H': {
          sy = i, sx = j;
        } break;
        case '#': {
          ty = i, tx = j;
        } break;
        case 'J': {
          arr[0].push_back({i, j});
        } break;
        case 'C': {
          arr[1].push_back({i, j});
        } break;
        case 'B': {
          arr[2].push_back({i, j});
        } break;
        case 'W': {
          arr[3].push_back({i, j});
        } break;
      }
    }
  }

  for (int i = 0; i < 4; i++) {
    arr[i].insert(arr[i].begin(), {sy, sx});
    arr[i].push_back({ty, tx});
  }

  int minn = INT_MAX, midx;
  for (int i = 0; i < 4; i++) {
    int order[5] = {0, 1, 2, 3, 4};
    do {
      int cur = 0;
      for (int j = 1; j < 5; j++) {
        auto [y1, x1] = arr[i][order[j - 1]];
        auto [y2, x2] = arr[i][order[j]];
        cur += abs(y1 - y2) + abs(x1 - x2);
      }
      if (minn > cur) minn = cur, midx = i;
    } while (next_permutation(order + 1, order + 4));
  }

  cout << kStr[midx];

  return 0;
}