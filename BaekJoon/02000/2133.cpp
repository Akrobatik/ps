// Title : 타일 채우기
// Link  : https://www.acmicpc.net/problem/2133 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int memo[31] = {1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 2; i <= n; i += 2) {
    for (int j = 0; j < i; j += 2) {
      memo[i] += (memo[j] << 1);
    }
    memo[i] += memo[i - 2];
  }
  cout << memo[n];

  return 0;
}
