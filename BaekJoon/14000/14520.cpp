// Title : Trapezi
// Link  : https://www.acmicpc.net/problem/14520 
// Time  : 28 ms
// Memory: 2168 KB

#include <bits/stdc++.h>

using namespace std;

struct DLX {
  void Init(int cols, const vector<vector<int>>& covers) {
    int total = cols + 1;
    for (auto& e : covers) total += e.size();

    id.clear(), id.resize(total);
    size.clear(), size.resize(cols + 1);
    head.clear(), head.resize(total);
    up.clear(), up.resize(total);
    down.clear(), down.resize(total);
    left.clear(), left.resize(total);
    right.clear(), right.resize(total);

    // Root
    left[0] = cols;
    right[0] = 1;

    // Columns
    int l = 0, r = 2;
    for (int i = 1; i <= cols; i++) {
      id[i] = l;
      size[i] = 0;
      head[i] = up[i] = down[i] = i;
      left[i] = l++;
      right[i] = r++;
    }
    right[cols] = 0;

    // Covers
    int cur = cols + 1;
    int rows = covers.size();
    for (int rid = 0; rid < rows; rid++) {
      int n = covers[rid].size();
      if (!n) continue;

      for (int _cid : covers[rid]) {
        int cid = _cid + 1;
        if (down[cid] == cid) down[cid] = cur;
        ++size[cid];
        id[cur] = rid;
        down[up[cid]] = cur;
        up[cur] = up[cid];
        up[cid] = cur;
        head[cur] = down[cur] = cid;
        left[cur] = cur - 1;
        right[cur] = cur + 1;
        ++cur;
      }
      left[cur - n] += n;
      right[cur - 1] -= n;
    }

    // Cover childless columns
    for (int i = 1; i <= cols; i++) {
      if (size[i]) continue;
      right[left[i]] = right[i];
      left[right[i]] = left[i];
    }
  }

  void CoverColumn(int col) {
    right[left[col]] = right[col];
    left[right[col]] = left[col];
    for (int row = down[col]; row != col; row = down[row]) {
      for (int node = right[row]; node != row; node = right[node]) {
        down[up[node]] = down[node];
        up[down[node]] = up[node];
        --size[head[node]];
      }
    }
  }

  void UncoverColumn(int col) {
    for (int row = up[col]; row != col; row = up[row]) {
      for (int node = left[row]; node != row; node = left[node]) {
        ++size[head[node]];
        down[up[node]] = node;
        up[down[node]] = node;
      }
    }
    right[left[col]] = col;
    left[right[col]] = col;
  }

  int FindMinColumn() {
    int min_col = right[0];
    int minn = size[min_col];
    for (int col = right[min_col]; col; col = right[col]) {
      if (minn > size[col]) min_col = col, minn = size[col];
    }
    return min_col;
  }

  bool Search() {
    if (!right[0]) return true;
    int col = FindMinColumn();
    CoverColumn(col);
    for (int row = down[col]; row != col; row = down[row]) {
      solution.push_back(id[row]);
      for (int node = right[row]; node != row; node = right[node]) CoverColumn(head[node]);
      if (Search()) return true;
      for (int node = left[row]; node != row; node = left[node]) UncoverColumn(head[node]);
      solution.pop_back();
    }
    UncoverColumn(col);
    return false;
  }

  vector<int> id, size;
  vector<int> head, up, down, left, right;
  vector<int> solution;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  char board[10][20];
  memset(board, 0, sizeof(board));

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    auto ptr = board[i];
    ptr += n - i - 1;
    for (auto c : s) *ptr++ = c;
  }
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    auto ptr = board[i + n];
    ptr += i;
    for (auto c : s) *ptr++ = c;
  }

  int cnt = 0;
  for (int i = 0; i < (n << 1); i++) {
    for (int j = 0; j < 20; j++) {
      cnt += (board[i][j] == '0');
    }
  }

  if (cnt % 3 != 0) {
    cout << "nemoguce";
    return 0;
  }

  unordered_map<int, array<int, 6>> mrow;
  unordered_map<int, vector<int>> mcol;

  auto Check = [&](int y, int x) {
    return 0 <= y && y < 10 && 0 <= x && x < 20;
  };

  auto Insert = [&](int y1, int x1, int y2, int x2, int y3, int x3) {
    if (!Check(y1, x1) || !Check(y2, x2) || !Check(y3, x3) ||
        board[y1][x1] != '0' || board[y2][x2] != '0' || board[y3][x3] != '0') return;

    int id = mrow.size();
    mrow[id] = {y1, x1, y2, x2, y3, x3};
    mcol[(y1 << 16) | x1].push_back(id);
    mcol[(y2 << 16) | x2].push_back(id);
    mcol[(y3 << 16) | x3].push_back(id);
  };

  for (int i = 0; i < (n << 1); i++) {
    for (int j = 0; j < 20; j++) {
      if (board[i][j] != '0') continue;

      if ((i + j + n) & 1) {
        Insert(i, j, i, j + 1, i, j + 2);
        Insert(i, j, i + 1, j, i + 1, j - 1);
        Insert(i, j, i + 1, j, i + 1, j + 1);
      } else {
        Insert(i, j, i, j + 1, i, j + 2);
        Insert(i, j, i, j - 1, i + 1, j - 1);
        Insert(i, j, i, j + 1, i + 1, j + 1);
      }
    }
  }

  if (mcol.size() != cnt) {
    cout << "nemoguce";
    return 0;
  }

  int idx = 0;
  vector<vector<int>> nodes(mrow.size());
  for (int i = 0; i < (n << 1); i++) {
    for (int j = 0; j < 20; j++) {
      if (board[i][j] == '0') {
        auto& rids = mcol[(i << 16) | j];
        for (auto rid : rids) nodes[rid].push_back(idx);
        ++idx;
      }
    }
  }

  DLX dlx;
  dlx.Init(cnt, nodes);
  if (dlx.Search()) {
    auto& sol = dlx.solution; 
    for (auto id : sol) {
      bool check[9] = {};
      auto& arr = mrow[id];
      for (int i = 0; i < 6; i += 2) {
        int y = arr[i], x = arr[i + 1];

        array<pair<int, int>, 3> delta;
        delta[0] = {y, x - 1};
        delta[1] = {y, x + 1};
        delta[2] = {y + (((y + x + n) & 1) << 1) - 1, x};
        for (auto [yy, xx] : delta) {
          if (Check(yy, xx) && board[yy][xx] >= '1') {
            check[board[yy][xx] - '1'] = true;
          }
        }
      }

      int type = 0;
      while (check[type]) ++type;
      for (int i = 0; i < 6; i += 2) {
        int y = arr[i], x = arr[i + 1];
        board[y][x] = '1' + type;
      }
    }

    for (int i = 0; i < (n << 1); i++) {
      for (int j = 0; j < 20; j++) {
        if (board[i][j]) cout << board[i][j];
      }
      cout << "\n";
    }
  } else {
    cout << "nemoguce";
  }

  return 0;
}
