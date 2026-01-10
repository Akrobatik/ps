// Title : 완벽한 도시 설계
// Link  : https://www.acmicpc.net/problem/32721 
// Time  : 116 ms
// Memory: 10816 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> arr(n + 1), deg(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    ++deg[arr[i]];
  }

  int leaf = 0;
  vector<int8_t> vis(n + 1);
  for (int i = 1; i <= n; i++) {
    if (deg[i]) continue;
    ++leaf;

    int cur = i;
    while (!vis[cur]) {
      vis[cur] = 1;
      cur = arr[cur];
    }
  }

  int cyc = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    ++cyc;

    int cur = i;
    while (!vis[cur]) {
      vis[cur] = 1;
      cur = arr[cur];
    }
  }

  if (leaf == 0 && cyc == 1) {
    cout << "0";
  } else {
    cout << leaf + cyc;
  }

  return 0;
}