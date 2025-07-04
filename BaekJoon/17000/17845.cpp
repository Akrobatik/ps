// Title : 수강 과목
// Link  : https://www.acmicpc.net/problem/17845 
// Time  : 4 ms
// Memory: 2180 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> memo(n + 1, -1), mnxt(n + 1);
  memo[0] = 0;
  while (k--) {
    int x, y;
    cin >> x >> y;
    copy(memo.begin(), memo.end(), mnxt.begin());
    for (int i = 0; i + y <= n; i++) {
      if (memo[i] == -1) continue;
      mnxt[i + y] = max<int>(mnxt[i + y], memo[i] + x);
    }
    swap(memo, mnxt);
  }

  int maxx = 0;
  for (int i = 0; i <= n; i++) {
    maxx = max<int>(maxx, memo[i]);
  }
  cout << maxx;

  return 0;
}
