#include <bits/stdc++.h>

using namespace std;

int n, m;
int coords[301];
bool visited[301][301];
int memo[301][301];

int Calc(int cur, int rev, int rem) {
  if (rem == 0) return 0;

  auto& ret = memo[cur][rev];
  if (visited[cur][rev]) return ret;
  visited[cur][rev] = true;

  int l = min<int>(cur, rev);
  int r = cur ^ rev ^ l;
  if (l != 0) {
    ret = max<int>(ret, Calc(l - 1, r, rem - 1) - rem * (coords[cur] - coords[l - 1]) + m);
  }
  if (r + 1 != n) {
    ret = max<int>(ret, Calc(r + 1, l, rem - 1) - rem * (coords[r + 1] - coords[cur]) + m);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  bool zero = false;
  for (int i = 0; i < n; i++) {
    cin >> coords[i];
    if (coords[i] == 0) zero = true;
  }
  if (!zero) coords[n++] = 0;
  sort(coords, coords + n);

  int maxx = 0;
  int zidx = lower_bound(coords, coords + n, 0) - coords;
  for (int i = 0; i <= n; i++) {
    memset(visited, 0, sizeof(visited));
    memset(memo, 0, sizeof(memo));
    maxx = max<int>(maxx, Calc(zidx, zidx, i));
  }
  cout << maxx + (zero ? m : 0);

  return 0;
}
