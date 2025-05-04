// Title : 사탕 가게
// Link  : https://www.acmicpc.net/problem/4781 
// Time  : 320 ms
// Memory: 2184 KB

#include <bits/stdc++.h>

using namespace std;

int Read() {
  char c;
  int x, y;
  cin >> x >> c >> y;
  return x * 100 + y;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<pair<int, int>> arr;

  int n, m;
  while (cin >> n && n) {
    m = Read();
    arr.resize(n);
    for (auto& [p, c] : arr) cin >> c, p = Read();
    sort(arr.begin(), arr.end());

    int memo[10001] = {};
    for (int i = arr[0].first; i <= m; i++) {
      memo[i] = memo[i - 1];
      for (auto [p, c] : arr) {
        if (i < p) break;
        memo[i] = max<int>(memo[i], memo[i - p] + c);
      }
    }
    cout << memo[m] << "\n";
  }

  return 0;
}
