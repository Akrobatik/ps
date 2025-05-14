// Title : 게임
// Link  : https://www.acmicpc.net/problem/1191 
// Time  : 568 ms
// Memory: 19296 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

char board[300][300];

vector<vector<int>> GetDistance(int sy, int sx, int n) {
  vector<vector<int>> dist(n, vector<int>(n, -1));
  queue<pair<int, int>> q;

  auto Push = [&](int y, int x, int d) {
    if (0 <= y && y < n && 0 <= x && x < n && dist[y][x] == -1 && board[y][x] != '#') {
      dist[y][x] = d;
      q.push({y, x});
    }
  };

  Push(sy, sx, 0);
  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();

    for (auto [dy, dx] : kDelta) {
      Push(y + dy, x + dx, dist[y][x] + 1);
    }
  }
  return dist;
}

void Solve() {
  int n;
  cin >> n;
  int ay, ax, by, bx;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'A') ay = i, ax = j;
      if (board[i][j] == 'B') by = i, bx = j;
    }
  }

  auto da = GetDistance(ay, ax, n), db = GetDistance(by, bx, n);
  int bound = da[by][bx];
  if (bound & 1) {
    cout << "A\n";
    return;
  }

  vector<vector<pair<int, int>>> arr(bound + 1), brr(bound + 1);
  map<tuple<int, int, int>, int> aidx, bidx;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int av = da[i][j], bv = db[i][j];
      if (av >= 0 && bv >= 0 && av + bv == bound) {
        aidx[{av, i, j}] = arr[av].size();
        arr[av].push_back({i, j});
        bidx[{bv, i, j}] = brr[bv].size();
        brr[bv].push_back({i, j});
      }
    }
  }

  vector<vector<array<int, 4>>> axr(bound), bxr(bound);
  for (int i = 0; i < bound; i++) {
    axr[i].reserve(arr[i].size());
    for (auto [y, x] : arr[i]) {
      auto it = axr[i].emplace_back().begin();
      for (auto [dy, dx] : kDelta) {
        int yy = y + dy, xx = x + dx;
        if (0 <= yy && yy < n && 0 <= xx && xx < n && aidx.contains({i + 1, yy, xx})) {
          *it++ = aidx[{i + 1, yy, xx}];
        } else {
          *it++ = -1;
        }
      }
    }

    bxr[i].reserve(brr[i].size());
    for (auto [y, x] : brr[i]) {
      auto it = bxr[i].emplace_back().begin();
      for (auto [dy, dx] : kDelta) {
        int yy = y + dy, xx = x + dx;
        if (0 <= yy && yy < n && 0 <= xx && xx < n && bidx.contains({i + 1, yy, xx})) {
          *it++ = bidx[{i + 1, yy, xx}];
        } else {
          *it++ = -1;
        }
      }
    }
  }

  int sz = arr[bound >> 1].size();
  vector<vector<bool>> memo(sz, vector<bool>(sz, true));
  for (int i = 0; i < sz; i++) memo[i][i] = false;

  int half = bound >> 1;
  for (int k = 1; k <= half; k++) {
    int na = arr[half - k].size(), nb = brr[half - k].size();
    vector<vector<bool>> mnxt(na, vector<bool>(nb));
    for (int i = 0; i < na; i++) {
      for (int j = 0; j < nb; j++) {
        bool ok = false;
        for (auto ai : axr[half - k][i]) {
          if (ai == -1) continue;
          bool pass = true;
          for (auto bi : bxr[half - k][j]) {
            if (bi == -1 || memo[ai][bi]) continue;
            pass = false;
            break;
          }
          if (pass) {
            ok = true;
            break;
          }
        }
        mnxt[i][j] = ok;
      }
    }
    memo.swap(mnxt);
  }

  cout << (memo[aidx[{0, ay, ax}]][bidx[{0, by, bx}]] ? "A\n" : "B\n");
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) Solve();

  return 0;
}
