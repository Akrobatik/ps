#include <bits/stdc++.h>

using namespace std;

int kids[30001][4];
int memo[3001];

int Find(int id, int& depth) {
  ++depth;
  if (kids[id][1] == id) return id;
  return kids[id][1] = Find(kids[id][1], depth);
}

void Union(int a, int b) {
  int da = 0, db = 0;
  int pa = Find(a, da);
  int pb = Find(b, db);
  if (pa != pb) {
    if (da < db) swap(pa, pb);
    kids[pa][0] += kids[pb][0];
    kids[pa][2] += kids[pb][2];
    kids[pb][0] = 0;
    kids[pb][1] = pa;
    kids[pb][2] = 0;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 1; i <= n; i++) {
    cin >> kids[i][0];
    kids[i][1] = i;
    kids[i][2] = 1;
  }

  while (m--) {
    int a, b;
    cin >> a >> b;
    Union(a, b);
  }

  vector<pair<int, int>> vec;
  vec.reserve(n);
  for (int i = 1; i <= n; i++) {
    if (kids[i][0]) vec.push_back({kids[i][2], kids[i][0]});
  }

  int maxx = 0;
  memset(memo, -1, k << 2);
  memo[0] = 0;
  for (auto [n_kids, candy] : vec) {
    for (int i = min<int>(maxx, k - n_kids - 1); i >= 0; i--) {
      if (memo[i] == -1) continue;
      memo[i + n_kids] = max<int>(memo[i + n_kids], memo[i] + candy);
    }
    maxx += n_kids;
  }

  cout << *max_element(memo, memo + k);

  return 0;
}
