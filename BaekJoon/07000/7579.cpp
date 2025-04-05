// Title : 앱
// Link  : https://www.acmicpc.net/problem/7579
// Time  : 0 ms
// Memory: 2100 KB

#include <bits/stdc++.h>

using namespace std;

int _memo[2][10001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  int mems[100];
  int costs[100];

  for (int i = 0; i < n; i++) cin >> mems[i];
  for (int i = 0; i < n; i++) cin >> costs[i];

  int maxx = 0;
  int* memo = _memo[1];
  int* memo_old = _memo[0];
  for (int i = 0; i < n; i++) {
    int mem = mems[i];
    int cost = costs[i];
    copy(memo_old, memo_old + cost, memo);
    for (int j = 0; j <= maxx; j++) memo[j + cost] = max<int>(memo_old[j + cost], memo_old[j] + mem);
    maxx += cost;
    swap(memo, memo_old);
  }

  int c = 0;
  while (memo_old[c] < m) c++;
  cout << c << endl;

  return 0;
}
