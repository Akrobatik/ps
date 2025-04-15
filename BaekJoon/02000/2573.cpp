// Title : 빙산
// Link  : https://www.acmicpc.net/problem/2573 
// Time  : 32 ms
// Memory: 2872 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int ans;
int n, m;
int board[300][300];
bool visited[300][300];
vector<pair<int, int>> ices;

pair<int, vector<int>> Calc() {
  vector<int> cnts(ices.size());
  int minn = INT_MAX;
  for (int i = 0; i < ices.size(); i++) {
    auto [y, x] = ices[i];
    for (auto [dy, dx] : kDelta) {
      if (board[y + dy][x + dx] == 0) ++cnts[i];
    }
    if (cnts[i]) minn = min<int>(minn, (board[y][x] + cnts[i] - 1) / cnts[i]);
  }
  return {minn, cnts};
}

void Update(int minn, const vector<int>& cnts) {
  ans += minn;
  vector<pair<int, int>> nxt;
  nxt.reserve(ices.size());
  for (int i = 0; i < ices.size(); i++) {
    auto [y, x] = ices[i];
    if (cnts[i]) board[y][x] = max<int>(board[y][x] - minn * cnts[i], 0);
    if (board[y][x]) nxt.push_back({y, x});
  }
  ices.swap(nxt);
}

bool Check() {
  memset(visited, 0, sizeof(visited));

  int cnt = 0;
  queue<pair<int, int>> q;
  visited[ices[0].first][ices[0].second] = true;
  q.push(ices[0]);
  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();

    ++cnt;
    for (auto [dy, dx] : kDelta) {
      int yy = y + dy, xx = x + dx;
      if (board[yy][xx] && !visited[yy][xx]) {
        visited[yy][xx] = true;
        q.push({yy, xx});
      }
    }
  }

  return cnt != ices.size();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if (board[i][j]) ices.push_back({i, j});
    }
  }

  while (!ices.empty()) {
    if (Check()) {
      cout << ans;
      return 0;
    }

    auto [minn, cnts] = Calc();
    Update(minn, cnts);
  }
  cout << "0";

  return 0;
}
