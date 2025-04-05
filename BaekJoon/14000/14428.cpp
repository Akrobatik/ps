// Title : 수열과 쿼리 16
// Link  : https://www.acmicpc.net/problem/14428
// Time  : 84 ms
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
      tree[i][j] = min<pair<int, int>>(tree[i - 1][j << 1], tree[i - 1][(j << 1) + 1]);
    }
  }

  return tree;
}

void UpdateTree(vector<vector<pair<int, int>>>& tree, int pos, int v) {
  tree[0][pos] = {v, pos};
  for (int i = 1; i < tree.size(); i++) {
    pos >>= 1;
    if (pos >= tree[i].size()) break;
    tree[i][pos] = min<pair<int, int>>(tree[i - 1][pos << 1], tree[i - 1][(pos << 1) + 1]);
  }
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

int MinIndex(vector<vector<pair<int, int>>>& tree, int a, int b) {
  pair<int, int> minn = {INT_MAX, INT_MAX};
  auto splits = Split(a, b);
  for (auto [aa, bb] : splits) {
    int d = log2(bb - aa + 1);

    minn = min<pair<int, int>>(minn, tree[d][aa >> d]);
  }
  return minn.second + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i].first;
    vec[i].second = i;
  }
  auto tree = MakeTree(vec);

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      UpdateTree(tree, b - 1, c);
    } else {
      cout << MinIndex(tree, b - 1, c - 1) << "\n";
    }
  }

  return 0;
}
