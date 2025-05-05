// Title : Kaisar - 생존
// Link  : https://www.acmicpc.net/problem/20506 
// Time  : 28 ms
// Memory: 5928 KB

#include <bits/stdc++.h>

using namespace std;

int par[200001], deg[200001], cnts[200001];
int64_t memo[200001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  deg[0] = 1;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    par[i] = x;
    ++deg[x];
  }

  for (int i = 1; i <= n; i++) {
    if (deg[i]) continue;

    int cur = i;
    do {
      --deg[cur];
      int nxt = par[cur];
      int64_t x = ++cnts[cur];
      cnts[nxt] += x;
      memo[cur] += x * x;
      memo[nxt] -= x * x;
      cur = nxt;
    } while (--deg[cur] == 0);
  }

  int64_t o = 0, e = 0, cur = 0;
  for (int i = 1; i <= n; i++) {
    int64_t cnt = memo[i], half = cnt >> 1;
    o += half * i, e += half * i;
    cur += cnt;
    if (cnt & 1) {
      if (cur & 1) {
        o += i;
      } else {
        e += i;
      }
    }
  }
  cout << e << " " << o;

  return 0;
}
