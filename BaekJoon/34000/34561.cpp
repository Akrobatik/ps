// Title : 수열과 쿼리 2025
// Link  : https://www.acmicpc.net/problem/34561 
// Time  : 148 ms
// Memory: 10620 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMaxN = 3e5;
constexpr int kMaxM = 5e5;
constexpr int kMax = kMaxN + kMaxM;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> memo(kMax + 1);
  iota(memo.begin(), memo.end(), 0);

  vector<int> vals(kMax + 1);
  iota(vals.begin(), vals.end(), 0);

  auto Find = [&](int id) {
    while (id != memo[id]) {
      int par = memo[id];
      id = memo[id] = memo[par];
    }
    return id;
  };

  vector<int> root(kMaxN + 1);
  iota(root.begin(), root.end(), 0);

  int n;
  cin >> n;
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) cin >> arr[i];

  int m;
  cin >> m;
  int idx = kMaxN;
  while (m--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int x, y;
      cin >> x >> y;
      int rx = root[x], ry = root[y];
      if (rx == -1) continue;

      if (ry != -1) {
        memo[rx] = ry;
        root[x] = -1;
      } else {
        int cur = ++idx;
        memo[rx] = cur;
        root[x] = -1, root[y] = cur;
        vals[cur] = y;
      }
    } else {
      int z;
      cin >> z;
      cout << vals[Find(arr[z])] << "\n";
    }
  }

  return 0;
}