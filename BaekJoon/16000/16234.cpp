// Title : 인구 이동
// Link  : https://www.acmicpc.net/problem/16234 
// Time  : 60 ms
// Memory: 2172 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int board[50][50];
bool visited[50][50];
vector<vector<pair<int, int>>> groups;

bool Check(int y, int x, int n, int l, int r) {
  int pops = board[y][x];
  for (auto [dy, dx] : kDelta) {
    int yy = y + dy, xx = x + dx;
    if (0 <= yy && yy < n && 0 <= xx && xx < n && !visited[yy][xx]) {
      int delta = abs(pops - board[yy][xx]);
      if (l <= delta && delta <= r) return true;
    }
  }
  return false;
}

void Traverse(int sy, int sx, int n, int l, int r) {
  visited[sy][sx] = true;
  if (!Check(sy, sx, n, l, r)) return;

  auto& group = groups.emplace_back();

  queue<pair<int, int>> q;
  q.push({sy, sx});
  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();

    int pops = board[y][x];
    group.push_back({y, x});
    for (auto [dy, dx] : kDelta) {
      int yy = y + dy, xx = x + dx;
      if (0 <= yy && yy < n && 0 <= xx && xx < n && !visited[yy][xx]) {
        int delta = abs(pops - board[yy][xx]);
        if (l <= delta && delta <= r) {
          visited[yy][xx] = true;
          q.push({yy, xx});
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, l, r;
  cin >> n >> l >> r;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }

  for (int i = 0;; i++) {
    memset(visited, 0, sizeof(visited));
    groups.clear();

    for (int y = 0; y < n; y++) {
      for (int x = 0; x < n; x++) {
        if (visited[y][x]) continue;
        Traverse(y, x, n, l, r);
      }
    }

    if (groups.empty()) {
      cout << i;
      break;
    }

    for (auto& group : groups) {
      int sum = 0;
      for (auto [y, x] : group) sum += board[y][x];
      sum /= group.size();
      for (auto [y, x] : group) board[y][x] = sum;
    }
  }

  return 0;
}
