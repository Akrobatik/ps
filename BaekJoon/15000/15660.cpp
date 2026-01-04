// Title : 테트로미노 (2)
// Link  : https://www.acmicpc.net/problem/15660 
// Time  : 828 ms
// Memory: 224136 KB

#include <bits/stdc++.h>

using namespace std;

using Block = array<pair<int, int>, 4>;

constexpr Block kDefaultBlocks[] = {
    {{{0, 0}, {0, 1}, {0, 2}, {0, 3}}},
    {{{0, 0}, {0, 1}, {1, 0}, {1, 1}}},
    {{{0, 0}, {1, 0}, {2, 0}, {2, 1}}},
    {{{0, 0}, {1, 0}, {1, 1}, {2, 1}}},
    {{{0, 0}, {0, 1}, {0, 2}, {1, 1}}},
};

constexpr array<Block, 19> kBlocks = []() {
  auto Flip = [](const Block& src) {
    array<pair<int, int>, 4> dst{};
    int maxx = 0;
    for (auto [y, x] : src) {
      maxx = max<int>(maxx, x);
    }
    for (int i = 0; i < 4; i++) {
      auto [sy, sx] = src[i];
      dst[i] = {sy, maxx - sx};
    }
    sort(dst.begin(), dst.end());
    return dst;
  };

  auto Rotate = [](const Block& src) {
    array<pair<int, int>, 4> dst{};
    int maxx = 0;
    for (auto [y, x] : src) {
      maxx = max<int>(maxx, x);
    }
    for (int i = 0; i < 4; i++) {
      auto [sy, sx] = src[i];
      dst[i] = {maxx - sx, sy};
    }
    sort(dst.begin(), dst.end());
    return dst;
  };

  auto Contains = [](span<Block> blocks, array<pair<int, int>, 4> key) {
    bool found = false;
    int n = blocks.size();
    for (int i = 0; !found && i < n; i++) {
      auto& block = blocks[i];
      int cnt = 0;
      for (int j = 0; j < 4; j++) {
        cnt += (block[j] == key[j] && block[j] == key[j]);
      }
      found = (cnt == 4);
    }
    return found;
  };

  array<Block, 19> blocks{};
  auto b = blocks.data();
  for (int j = 0; j < 5; j++) {
    auto e = b;
    auto block = kDefaultBlocks[j];
    for (int i = 0; i < 4; i++) {
      if (!Contains(ranges::subrange(b, e), block)) *e++ = block;
      block = Rotate(block);
    }
    block = Flip(block);
    for (int i = 0; i < 4; i++) {
      if (!Contains(ranges::subrange(b, e), block)) *e++ = block;
      block = Rotate(block);
    }
    b = e;
  }
  return blocks;
}();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> mat(n, vector<int>(m));
  for (auto& vec : mat) {
    for (auto& e : vec) cin >> e;
  }

  auto Check = [&](int y, int x, const Block& block) {
    for (auto [yy, xx] : block) {
      yy += y, xx += x;
      if (0 <= yy && yy < n && 0 <= xx && xx < m) continue;
      return false;
    }
    return true;
  };

  auto Calc = [&](const Block& block) {
    int res = 0;
    for (auto [y, x] : block) res += mat[y][x];
    return res;
  };

  vector<pair<int, Block>> cands;
  for (auto& block : kBlocks) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (Check(i, j, block)) {
          Block b = block;
          for (auto& [y, x] : b) y += i, x += j;
          cands.push_back({Calc(b), b});
        }
      }
    }
  }
  sort(cands.begin(), cands.end(), greater<pair<int, Block>>());

  int maxx = 0, nc = cands.size();
  vector<vector<int8_t>> vis(n, vector<int8_t>(m));
  for (int i = 0; i < nc; i++) {
    int cur = cands[i].first;
    for (auto [y, x] : cands[i].second) vis[y][x] = 1;
    for (int j = i + 1; j < nc && cur + cands[j].first > maxx; j++) {
      bool ok = true;
      for (auto [y, x] : cands[j].second) {
        ok &= (vis[y][x] == 0);
      }

      if (ok) {
        maxx = cur + cands[j].first;
        break;
      }
    }
    for (auto [y, x] : cands[i].second) vis[y][x] = 0;
  }
  cout << maxx;

  return 0;
}