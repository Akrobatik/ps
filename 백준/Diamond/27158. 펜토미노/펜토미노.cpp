#include <bits/stdc++.h>

using namespace std;

struct DLX {
  void Init(int cols, vector<vector<int>>& covers) {
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

using Block = array<pair<int, int>, 5>;

constexpr const char* kBlockTypes = "FILNPTUVWXYZ";

constexpr Block kDefaultBlocks[] = {
    {{{0, 1}, {0, 2}, {1, 0}, {1, 1}, {2, 1}}},  // F
    {{{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}}},  // I
    {{{0, 0}, {1, 0}, {2, 0}, {3, 0}, {3, 1}}},  // L
    {{{0, 1}, {1, 0}, {1, 1}, {2, 0}, {3, 0}}},  // N
    {{{0, 0}, {0, 1}, {1, 0}, {1, 1}, {2, 0}}},  // P
    {{{0, 0}, {0, 1}, {0, 2}, {1, 1}, {2, 1}}},  // T
    {{{0, 0}, {0, 2}, {1, 0}, {1, 1}, {1, 2}}},  // U
    {{{0, 0}, {1, 0}, {2, 0}, {2, 1}, {2, 2}}},  // V
    {{{0, 0}, {1, 0}, {1, 1}, {2, 1}, {2, 2}}},  // W
    {{{0, 1}, {1, 0}, {1, 1}, {1, 2}, {2, 1}}},  // X
    {{{0, 1}, {1, 0}, {1, 1}, {2, 1}, {3, 1}}},  // Y
    {{{0, 0}, {0, 1}, {1, 1}, {2, 1}, {2, 2}}},  // Z
};

constexpr array<pair<int, Block>, 63> kBlocks = []() {
  auto Flip = [](const Block& src) {
    array<pair<int, int>, 5> dst{};
    int maxx = 0;
    for (auto [y, x] : src) {
      maxx = max<int>(maxx, x);
    }
    for (int i = 0; i < 5; i++) {
      auto [sy, sx] = src[i];
      dst[i] = {sy, maxx - sx};
    }
    sort(dst.begin(), dst.end());
    return dst;
  };

  auto Rotate = [](const Block& src) {
    array<pair<int, int>, 5> dst{};
    int maxx = 0;
    for (auto [y, x] : src) {
      maxx = max<int>(maxx, x);
    }
    for (int i = 0; i < 5; i++) {
      auto [sy, sx] = src[i];
      dst[i] = {maxx - sx, sy};
    }
    sort(dst.begin(), dst.end());
    return dst;
  };

  auto Contains = [](span<pair<int, Block>> blocks, array<pair<int, int>, 5> key) {
    bool found = false;
    int n = blocks.size();
    for (int i = 0; !found && i < n; i++) {
      auto& block = blocks[i].second;
      int cnt = 0;
      for (int j = 0; j < 5; j++) {
        cnt += (block[j].first == key[j].first && block[j].second == key[j].second);
      }
      found = (cnt == 5);
    }
    return found;
  };

  array<pair<int, Block>, 63> blocks{};
  auto b = blocks.data();
  for (int j = 0; j < 12; j++) {
    auto e = b;
    auto block = kDefaultBlocks[j];
    for (int i = 0; i < 4; i++) {
      if (!Contains(ranges::subrange(b, e), block)) *e++ = {j, block};
      block = Rotate(block);
    }
    block = Flip(block);
    for (int i = 0; i < 4; i++) {
      if (!Contains(ranges::subrange(b, e), block)) *e++ = {j, block};
      block = Rotate(block);
    }
    b = e;
  }
  return blocks;
}();

char board[100][100];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int coord_idx = 0;
  unordered_map<int, int> m_coords;

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if (board[i][j] == '0') {
        m_coords[(i << 16) | j] = coord_idx++;
      }
    }
  }

  int cols = 60 + 12, rows = n * m * 63;
  vector<vector<int>> covers(rows);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < 63; k++) {
        bool ok = true;
        for (auto [dy, dx] : kBlocks[k].second) {
          int y = i + dy, x = j + dx;
          if (0 <= y && y < n && 0 <= x && x < m && board[y][x] == '0') continue;
          ok = false;
          break;
        }
        if (!ok) continue;

        int row_id = (i * m + j) * 63 + k;
        auto& [kind, block] = kBlocks[k];
        covers[row_id].reserve(6);
        covers[row_id].push_back(kind + 60);
        for (auto [dy, dx] : block) {
          int y = i + dy, x = j + dx;
          covers[row_id].push_back(m_coords[(y << 16) | x]);
        }
      }
    }
  }

  DLX dlx;
  dlx.Init(cols, covers);
  dlx.Search();
  for (auto row_id : dlx.solution) {
    int y = row_id / (m * 63);
    int x = row_id / 63 % m;
    int k = row_id % 63;
    auto& [kind, block] = kBlocks[k];
    for (auto [dy, dx] : block) {
      board[y + dy][x + dx] = kBlockTypes[kind];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << board[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
