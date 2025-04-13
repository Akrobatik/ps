// Title : 부동산 다툼
// Link  : https://www.acmicpc.net/problem/20364 
// Time  : 44 ms
// Memory: 3044 KB

#include <bits/stdc++.h>

using namespace std;

bool tree[1 << 20];
int seq[32];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  while (q--) {
    int x;
    cin >> x;

    int nx = 0, xx = x;
    while (xx) seq[nx++] = xx, xx >>= 1;

    int ans = 0;
    while (nx--) {
      if (tree[seq[nx]]) {
        ans = seq[nx];
        break;
      }
    }

    if (ans == 0) tree[x] = true;
    cout << ans << "\n";
  }

  return 0;
}
