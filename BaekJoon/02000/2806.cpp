// Title : DNA 발견
// Link  : https://www.acmicpc.net/problem/2806 
// Time  : 8 ms
// Memory: 10984 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;

  vector<array<int, 2>> memo(n + 1);
  for (int i = 0; i < n; i++) {
    int a = (s[i] == 'A' ? 0 : 1), b = a ^ 1;
    memo[i + 1][a] = min<int>(memo[i][a], memo[i][b] + 1);
    memo[i + 1][b] = memo[i][b] + 1;
  }
  cout << min<int>(memo[n][0], memo[n][1] + 1);

  return 0;
}