// Title : 선거구 나누기
// Link  : https://www.acmicpc.net/problem/2203 
// Time  : 1080 ms
// Memory: 31288 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int m = n * 3;
  vector<int> arr(m + 1);
  for (int i = 1; i <= m; i++) {
    cin >> arr[i];
  }

  vector<int> ids(m);
  iota(ids.begin(), ids.end(), 1);
  sort(ids.begin(), ids.end(), [&](int lhs, int rhs) {
    return arr[lhs] > arr[rhs];
  });

  m = n << 1;
  ids.resize(m);

  int sum = 0;
  for (auto e : ids) sum += arr[e];
  int lb = n * 500 + 1, ub = sum - lb;

  int maxx = m * 1000;
  vector<vector<int>> memo(n + 1, vector<int>(maxx + 1, -1));
  memo[0][0] = true;
  for (int i = 0; i < m; i++) {
    int x = arr[ids[i]];
    for (int j = n; j > 0; j--) {
      for (int k = maxx; k >= x; k--) {
        if (memo[j][k] != -1) continue;
        if (memo[j - 1][k - x] != -1) memo[j][k] = ids[i];
      }
    }
  }

  vector<bool> oks(n + m + 1);
  for (auto i : ids) oks[i] = true;

  int st = ub;
  while (memo[n][st] == -1) --st;

  for (int i = n; i > 0; i--) {
    int id = memo[i][st];
    int x = arr[id];
    st -= x;
    oks[id] = false;
    cout << id << "\n";
  }

  for (int i = 1; i <= n + m; i++) {
    if (!oks[i]) continue;
    cout << i << "\n";
  }

  for (auto i : ids) oks[i] = true;

  for (int i = 1; i <= n + m; i++) {
    if (oks[i]) continue;
    cout << i << "\n";
  }

  return 0;
}