// Title : 우주 탐사선
// Link  : https://www.acmicpc.net/problem/17182 
// Time  : 16 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int ans;
int memo[10][10];
bool visited[10];

void Traverse(int cur, int sum, int cnt, int maxx) {
  if (cnt == maxx) {
    ans = min<int>(ans, sum);
    return;
  }

  visited[cur] = true;
  for (int i = 0; i < maxx; i++) {
    if (visited[i]) continue;
    Traverse(i, sum + memo[cur][i], cnt + 1, maxx);
  }
  visited[cur] = false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> memo[i][j];
    }
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        memo[i][j] = min<int>(memo[i][j], memo[i][k] + memo[k][j]);
      }
    }
  }

  ans = INT_MAX;
  Traverse(k, 0, 1, n);
  cout << ans;

  return 0;
}
