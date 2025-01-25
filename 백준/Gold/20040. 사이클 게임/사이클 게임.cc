#include <bits/stdc++.h>

using namespace std;

int n, m;
int memo[500000];

int GetParent(int id, int& depth) {
  ++depth;
  if (memo[id] == id) return id;
  return memo[id] = GetParent(memo[id], depth);
}

bool Union(int a, int b) {
  int da = 0, db = 0;
  int pa = GetParent(a, da);
  int pb = GetParent(b, db);
  if (pa == pb) return false;
  if (da > db) swap(pa, pb);
  memo[pa] = pb;
  return true;
}

int Play() {
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    if (!Union(a, b)) return i + 1;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < n; i++) memo[i] = i;
  cout << Play() << "\n";

  return 0;
}
