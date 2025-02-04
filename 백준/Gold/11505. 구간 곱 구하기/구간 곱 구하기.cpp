#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kMod = 1000000007;

vector<vector<int64_t>> MakeTree(const vector<int64_t>& vec) {
  int n = vec.size();
  int l = (int)log2(n) + 1;
  vector<vector<int64_t>> tree(l);
  tree[0].resize(n);
  copy(vec.begin(), vec.end(), tree[0].begin());
  for (int i = 1; i < l; i++) {
    n >>= 1;
    tree[i].resize(n);
    for (int j = 0; j < n; j++) {
      tree[i][j] = (tree[i - 1][j << 1] * tree[i - 1][(j << 1) + 1]) % 1000000007;
    }
  }

  return tree;
}

void UpdateTree(vector<vector<int64_t>>& tree, int pos, int64_t v) {
  tree[0][pos] = v;
  for (int i = 1; i < tree.size(); i++) {
    pos >>= 1;
    if (pos >= tree[i].size()) break;
    tree[i][pos] = (tree[i - 1][pos << 1] * tree[i - 1][(pos << 1) + 1]) % kMod;
  }
}

int64_t Pick(vector<vector<int64_t>>& tree, int a, int b) {
  int d = log2(b - a + 1);
  return tree[d][a >> d];
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

int64_t Mul(vector<vector<int64_t>>& tree, int a, int b) {
  int64_t sum = 1;
  auto splits = Split(a, b);
  for (auto [aa, bb] : splits) sum = (sum * Pick(tree, aa, bb)) % kMod;
  return sum;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;
  vector<int64_t> vec(n);
  for (int i = 0; i < n; i++) cin >> vec[i];
  auto tree = MakeTree(vec);

  int nn = m + k;
  for (int i = 0; i < nn; i++) {
    int a, b;
    int64_t c;
    cin >> a >> b >> c;
    if (a == 1) {
      UpdateTree(tree, b - 1, c);
    } else {
      cout << Mul(tree, b - 1, c - 1) << "\n";
    }
  }

  return 0;
}
