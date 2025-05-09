// Title : 거스름돈
// Link  : https://www.acmicpc.net/problem/14916 
// Time  : 0 ms
// Memory: 2288 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int memo[100001] = {0, -1, 1, -1, 2, 1, 3, 2, 4, 3};

  int n;
  cin >> n;
  for (int i = 10; i <= n; i++) {
    memo[i] = min<int>(memo[i - 2], memo[i - 5]) + 1;
  }
  cout << memo[n];

  return 0;
}