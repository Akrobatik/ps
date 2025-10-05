// Title : DNA 발견
// Link  : https://www.acmicpc.net/problem/2806 
// Time  : 4 ms
// Memory: 3680 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;

  int mem[2][2] = {};
  int *memo = mem[0], *mnxt = mem[1];

  for (int i = 0; i < n; i++) {
    int a = (s[i] == 'A' ? 0 : 1), b = a ^ 1;
    mnxt[a] = min<int>(memo[a], memo[b] + 1);
    mnxt[b] = memo[b] + 1;
    swap(memo, mnxt);
  }
  cout << min<int>(memo[0], memo[1] + 1);

  return 0;
}