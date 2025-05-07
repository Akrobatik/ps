// Title : 점프는 즐거워
// Link  : https://www.acmicpc.net/problem/4383 
// Time  : 0 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> arr;
  vector<bool> visited;

  int n;
  while (cin >> n) {
    arr.resize(n);
    for (auto& e : arr) cin >> e;
    visited.assign(n, false);
    visited[0] = true;

    bool ok = true;
    for (int i = 1; i < n; i++) {
      int x = abs(arr[i - 1] - arr[i]);
      if (x >= n || visited[x]) {
        ok = false;
        break;
      }
      visited[x] = true;
    }

    cout << (ok ? "Jolly\n" : "Not jolly\n");
  }

  return 0;
}
