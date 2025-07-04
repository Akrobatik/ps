// Title : 자두나무
// Link  : https://www.acmicpc.net/problem/2240 
// Time  : 0 ms
// Memory: 2140 KB

#include <bits/stdc++.h>

using namespace std;

int memo[1001][31];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t, w;
  cin >> t >> w;
  vector<int> arr(t);
  for (auto& e : arr) cin >> e;

  int maxx = 0;
  for (int i = 0; i < t; i++) {
    for (int j = 0; j <= w; j++) {
      int p = (j & 1) + 1;
      int add = (arr[i] == p);
      memo[i + 1][j] = memo[i][j] + add;
      if (j) memo[i + 1][j] = max<int>(memo[i + 1][j], memo[i][j - 1] + add);
    }
  }
  for (int i = 0; i <= w; i++) maxx = max<int>(maxx, memo[t][i]);
  cout << maxx;

  return 0;
}
