#include <bits/stdc++.h>

using namespace std;

int memo[100001];
char ans[400001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  iota(memo + 1, memo + n + 1, 1);
  int maxx = 0;
  auto ptr = ans;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    if (maxx < v) {
      for (int i = maxx; i < v; i++) *ptr++ = '+', *ptr++ = '\n';
      *ptr++ = '-', *ptr++ = '\n';
      maxx = v;
      memo[v] = memo[v - 1];
    } else {
      *ptr++ = '-', *ptr++ = '\n';
      int vv = memo[maxx];
      if (memo[maxx] != v) {
        cout << "NO";
        return 0;
      }
      memo[maxx] = memo[memo[maxx] - 1];
    }
  }
  cout << ans;

  return 0;
}
