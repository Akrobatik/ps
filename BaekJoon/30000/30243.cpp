// Title : 🧩 N-Queen (Hard)
// Link  : https://www.acmicpc.net/problem/30243 
// Time  : 760 ms
// Memory: 2164 KB

#include <bits/stdc++.h>

using namespace std;

int nsize;

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
    if (min_col > nsize * 2) return 0;
    int minn = size[min_col];
    for (int col = right[min_col]; minn != 1 && col; col = right[col]) {
      if (col > nsize * 2) break;
      if (minn > size[col]) min_col = col, minn = size[col];
    }
    return min_col;
  }

  bool Search(int depth) {
    if (depth == nsize) return true;
    if (!right[0]) return false;
    int col = FindMinColumn();
    if (!col) return false;
    CoverColumn(col);
    for (int row = down[col]; row != col; row = down[row]) {
      solution.push_back(id[row]);
      for (int node = right[row]; node != row; node = right[node]) CoverColumn(head[node]);
      if (Search(depth + 1)) return true;
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

  int n;
  cin >> n;
  nsize = n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  bitset<64> cmask, rmask, pmask, mmask;

  auto Check = [&](int y, int x) {
    if (cmask.test(y)) return false;
    if (rmask.test(x)) return false;
    if (pmask.test(y + x)) return false;
    if (mmask.test(y - x + n - 1)) return false;
    return true;
  };

  int cnt = 0;
  for (int y = 0; y < n; y++) {
    if (arr[y] == 0) continue;
    int x = arr[y] - 1;
    if (!Check(y, x)) {
      cout << "-1";
      return 0;
    }
    ++cnt;
    cmask.set(y);
    rmask.set(x);
    pmask.set(y + x);
    mmask.set(y - x + n - 1);
  }

  int cols = n * 6 - 2;
  int rows = n * n;
  vector<vector<int>> covers(rows);
  for (int i = 0; i < rows; i++) {
    int y = i / n, x = i % n;
    if (Check(y, x)) {
      auto& cids = covers[i];
      cids.resize(4);
      cids[0] = y;
      cids[1] = x + n;
      cids[2] = y + x + n * 2;
      cids[3] = y - x + n * 5 - 2;
    }
  }

  DLX dlx;
  dlx.Init(cols, covers);
  if (dlx.Search(cnt)) {
    for (auto rid : dlx.solution) {
      int y = rid / n, x = rid % n;
      arr[y] = x + 1;
    }
    for (auto e : arr) cout << e << " ";
  } else {
    cout << "-1";
  }

  return 0;
}
