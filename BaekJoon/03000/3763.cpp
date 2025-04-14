// Title : 스도쿠
// Link  : https://www.acmicpc.net/problem/3763 
// Time  : 132 ms
// Memory: 2388 KB

#pragma comment(linker, "/STACK:167772160")
#pragma GCC optimize("O3")

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
    int min_col = left[0];
    int minn = size[min_col];
    for (int col = left[min_col]; minn != 1 && col; col = left[col]) {
      if (minn > size[col]) min_col = col, minn = size[col];
    }
    return min_col;
  }

  bool Search() {
    if (!right[0]) return true;
    int col = FindMinColumn();
    CoverColumn(col);

    vector<pair<int, int>> cands;
    cands.reserve(size[col]);
    for (int row = down[col]; row != col; row = down[row]) {
      int score = 0;
      for (int node = right[row]; node != row; node = right[node]) {
        score += size[head[node]];
      }
      cands.push_back({score, row});
    }
    sort(cands.begin(), cands.end());

    for (auto [_, row] : cands) {
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

constexpr int kSqrt = 4;
constexpr int kSize = kSqrt * kSqrt;
constexpr int kSqr = kSize * kSize;
constexpr int kCols = 4 * kSize * kSize;
constexpr int kRows = kSize * kSize * kSize;

int board[kSize][kSize];
bitset<kSize> sub_masks[kSize];
bitset<kSize> row_masks[kSize];
bitset<kSize> col_masks[kSize];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  for (int i = 0; i < kSize; i++) {
    for (int j = 0; j < kSize; j++) {
      char c;
      cin >> c;
      board[i][j] = c != '-' ? c - 'A' + 1 : 0;
      if (board[i][j]) {
        int s = i - i % kSqrt + j / kSqrt;
        int m = (1 << (board[i][j] - 1));
        sub_masks[s] |= m;
        row_masks[i] |= m;
        col_masks[j] |= m;
      }
    }
  }

  auto check = [&](int s, int y, int x, int v) {
    return board[y][x] == 0 &&
           !sub_masks[s].test(v) &&
           !row_masks[y].test(v) &&
           !col_masks[x].test(v);
  };

  vector<vector<int>> covers(kRows);

  int y = 0, x = 0, v = 0;
  for (int i = 0; i < kRows; i++) {
    int s = y - y % kSqrt + x / kSqrt;
    if (check(s, y, x, v)) {
      auto& cids = covers[i];
      cids.resize(4);
      cids[0] = y * kSize + x;
      cids[1] = s * kSize + v + kSqr;
      cids[2] = y * kSize + v + kSqr * 2;
      cids[3] = x * kSize + v + kSqr * 3;
    }

    if (++v == kSize) {
      v = 0;
      if (++x == kSize) {
        x = 0;
        ++y;
      }
    }
  }

  DLX dlx;
  dlx.Init(kCols, covers);
  dlx.Search();

  for (auto id : dlx.solution) {
    int y = id / (kSize * kSize);
    int x = (id / kSize) % kSize;
    int v = id % kSize;
    board[y][x] = v + 1;
  }

  for (int i = 0; i < kSize; i++) {
    for (int j = 0; j < kSize; j++) cout << (char)(board[i][j] + 'A' - 1);
    cout << "\n";
  }

  return 0;
}
