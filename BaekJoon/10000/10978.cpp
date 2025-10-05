// Title : 기숙사 재배정
// Link  : https://www.acmicpc.net/problem/10978 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t memo[21] = {1};

  for (int i = 1, j = -1; i <= 20; i++, j = -j) {
    memo[i] = memo[i - 1] * i + j;
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << memo[n] << "\n";
  }

  return 0;
}