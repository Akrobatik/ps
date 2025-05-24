// Title : 콩돌 놀이
// Link  : https://www.acmicpc.net/problem/33969 
// Time  : 0 ms
// Memory: 2172 KB

#include <bits/stdc++.h>

using namespace std;

struct DLX {
  void Init(int cols, span<vector<int>> covers) {
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
    for (int col = right[min_col]; minn != 1 && col; col = right[col]) {
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

  int n, m;
  cin >> n >> m;
  vector<string> board(n);
  for (auto& s : board) cin >> s;

  map<pair<int, int>, int> idx;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == 'x') idx[{i, j}] = idx.size();
    }
  }

  vector<vector<pair<int, int>>> def = {
      {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {2, 0}, {2, 1}, {2, 2}, {3, 2}, {4, 0}, {4, 1}, {4, 2}},
      {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {4, 1}, {4, 2}}};

  vector<vector<pair<int, int>>> blocks;

  auto Norm = [&](vector<pair<int, int>>& src) {
    int miny = INT_MAX, minx = INT_MAX;
    for (auto [y, x] : src) {
      miny = min<int>(miny, y);
      minx = min<int>(minx, x);
    }
    for (auto& [y, x] : src) {
      y -= miny;
      x -= minx;
    }
    sort(src.begin(), src.end());
  };

  auto Rotate = [&](const vector<pair<int, int>>& src) {
    vector<pair<int, int>> dst(src.size());
    int maxx = 0;
    for (auto [y, x] : src) {
      maxx = max<int>(maxx, x);
    }
    for (int i = 0; i < src.size(); i++) {
      auto [sy, sx] = src[i];
      dst[i] = {maxx - sx, sy};
    }
    Norm(dst);
    return dst;
  };

  for (int i = 0; i < 2; i++) {
    auto block = def[i];
    for (int j = 0; j < (i + 1) * 2; j++) {
      blocks.push_back(block);
      block = Rotate(block);
    }
  }

  vector<vector<int>> covers;
  vector<int> memo;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < blocks.size(); k++) {
        auto& block = blocks[k];
        vector<int> arr;
        for (auto [dy, dx] : block) {
          int y = i + dy, x = j + dx;
          if (auto it = idx.find({y, x}); it != idx.end()) {
            arr.push_back(it->second);
          } else {
            arr.clear();
            break;
          }
        }

        if (!arr.empty()) {
          covers.push_back(arr);
          memo.push_back((k < 2 ? 0 : 1));
        }
      }
    }
  }

  DLX dlx;
  dlx.Init(idx.size(), covers);
  dlx.Search();

  int ss = 0, cc = 0;
  for (int rid : dlx.solution) {
    if (memo[rid] == 0) {
      ++ss;
    } else {
      ++cc;
    }
  }
  cout << ss << " " << cc;

  return 0;
}
