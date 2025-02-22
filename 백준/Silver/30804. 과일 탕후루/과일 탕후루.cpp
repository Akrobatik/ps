#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int memo[10] = {};

  int n;
  cin >> n;
  int types = 0;
  queue<int> q;
  int ans = 0;
  while (n--) {
    int v;
    cin >> v;
    q.push(v);
    if (memo[v]++ == 0) {
      if (types == 2) {
        for (;;) {
          int vv = q.front();
          q.pop();
          if (--memo[vv] == 0) break;
        }
      } else {
        ++types;
      }
    }
    ans = max<int>(ans, q.size());
  }
  cout << ans;

  return 0;
}
