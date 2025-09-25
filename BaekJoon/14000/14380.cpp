// Title : BFFs (Large)
// Link  : https://www.acmicpc.net/problem/14380 
// Time  : 0 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int n;
    cin >> n;

    vector<int> arr(n + 1), deg(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
      ++deg[arr[i]];
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
      if (deg[i]) continue;
      q.push(i);
    }

    vector<int> memo(n + 1, 1);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      int nxt = arr[cur];
      memo[nxt] = max<int>(memo[nxt], memo[cur] + 1);
      if (--deg[nxt] == 0) q.push(nxt);
    }

    int maxx = 0;
    vector<bool> visited(n + 1);
    for (int i = 1; i <= n; i++) {
      if (visited[i] || deg[i] == 0) continue;

      int cur = i, len = 0;
      do {
        ++len;
        visited[cur] = true;
        cur = arr[cur];
      } while (cur != i);

      maxx = max<int>(maxx, len);
    }

    int two = 0;
    for (int i = 1; i <= n; i++) {
      if (arr[i] > i || arr[arr[i]] != i) continue;
      two += memo[i] + memo[arr[i]];
    }
    maxx = max<int>(maxx, two);

    cout << "Case #" << tc << ": " << maxx << "\n";
  }

  return 0;
}
