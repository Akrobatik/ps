// Title : NM과 K （1）
// Link  : https://www.acmicpc.net/problem/18290
// Time  : 20 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int ans = INT_MIN;
int n, m, k;
int mat[11][11];
bool pick[11][11];

void Traverse(int r, int c, int sum, int rem) {
  if (k == 0) {
    if (ans < sum) ans = sum;
    return;
  }
  if (rem-- < k) return;

  int nr, nc;
  if (c == m) {
    nr = r + 1;
    nc = 1;
  } else {
    nr = r;
    nc = c + 1;
  }

  if (!pick[r - 1][c] && !pick[r][c - 1]) {
    pick[r][c] = true;
    --k;
    Traverse(nr, nc, sum + mat[r][c], rem);
    ++k;
    pick[r][c] = false;
  }
  Traverse(nr, nc, sum, rem);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> mat[i][j];
    }
  }
  Traverse(1, 1, 0, n * m);
  cout << ans;

  return 0;
}
