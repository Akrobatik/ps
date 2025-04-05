// Title : 최솟값과 최댓값
// Link  : https://www.acmicpc.net/problem/2357
// Time  : 128 ms
// Memory: 4412 KB

#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> MakeTree(const vector<pair<int, int>>& vec) {
  int n = vec.size();
  int l = (int)log2(n) + 1;
  vector<vector<pair<int, int>>> tree(l);
  tree[0].resize(n);
  copy(vec.begin(), vec.end(), tree[0].begin());
  for (int i = 1; i < l; i++) {
    n >>= 1;
    tree[i].resize(n);
    for (int j = 0; j < n; j++) {
      int minn = min<int>(tree[i - 1][j << 1].first, tree[i - 1][(j << 1) + 1].first);
      int maxx = max<int>(tree[i - 1][j << 1].second, tree[i - 1][(j << 1) + 1].second);
      tree[i][j] = {minn, maxx};
    }
  }

  return tree;
}

vector<pair<int, int>> Split(int n, int m) {
  vector<pair<int, int>> result;

  int cur = n;
  while (cur <= m) {
    int step = 1;
    while (cur % (step << 1) == 0 && cur + (step << 1) - 1 <= m) step <<= 1;
    result.emplace_back(cur, min(cur + step - 1, m));
    cur += step;
  }
  return result;
}

pair<int, int> MinMax(vector<vector<pair<int, int>>>& tree, int a, int b) {
  int minn = INT_MAX;
  int maxx = INT_MIN;
  auto splits = Split(a, b);
  for (auto [aa, bb] : splits) {
    int d = log2(bb - aa + 1);
    minn = min<int>(minn, tree[d][aa >> d].first);
    maxx = max<int>(maxx, tree[d][aa >> d].second);
  }
  return {minn, maxx};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> vec(n);
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    vec[i] = {v, v};
  }
  auto tree = MakeTree(vec);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    auto [minn, maxx] = MinMax(tree, a - 1, b - 1);
    cout << minn << " " << maxx << "\n";
  }

  return 0;
}
