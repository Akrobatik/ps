#include <bits/stdc++.h>

using namespace std;

int memo[401][401][401];
int nxt[1001][100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int nt, te;
  cin >> nt >> te;
  vector<int> trr(nt);
  for (auto& e : trr) cin >> e;

  int na, nb, nc;
  cin >> na >> nb >> nc;
  vector<int> arr(na), brr(nb), crr(nc);
  for (auto& e : arr) cin >> e;
  for (auto& e : brr) cin >> e;
  for (auto& e : crr) cin >> e;

  for (int i = 1; i <= 1000; i++) {
    int r = te;
    for (auto l : views::reverse(trr)) {
      for (int j = r; j > l; j--) nxt[i][j] = j;
      r = min<int>(r, l - i);
    }
    r = 0;
    for (int j = te; j >= 0; j--) {
      if (nxt[i][j]) {
        r = j;
      } else {
        nxt[i][j] = r;
      }
    }
  }

  int ans;
  int nabc = na + nb + nc;
  fill_n((int*)memo, 401 * 401 * 401, INT_MAX);
  memo[0][0][0] = 0;
  for (ans = 0; ans < nabc; ans++) {
    bool none = true;
    for (int a = 0; a <= na && a <= ans; a++) {
      for (int b = 0; b <= nb && a + b <= ans; b++) {
        int c = ans - a - b;
        if (c > nc) continue;

        int cur = memo[a][b][c];
        if (cur == INT_MAX) continue;

        if (a < na) {
          int axt = nxt[arr[a]][cur];
          if (axt) {
            none = false;
            memo[a + 1][b][c] = min<int>(memo[a + 1][b][c], axt + arr[a]);
          }
        }

        if (b < nb) {
          int bxt = nxt[brr[b]][cur];
          if (bxt) {
            none = false;
            memo[a][b + 1][c] = min<int>(memo[a][b + 1][c], bxt + brr[b]);
          }
        }

        if (c < nc) {
          int cxt = nxt[crr[c]][cur];
          if (cxt) {
            none = false;
            memo[a][b][c + 1] = min<int>(memo[a][b][c + 1], cxt + crr[c]);
          }
        }
      }
    }
    if (none) break;
  }
  cout << ans;

  return 0;
}