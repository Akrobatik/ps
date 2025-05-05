// Title : Punkty rankingowe
// Link  : https://www.acmicpc.net/problem/26675 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n + 1), memo(n + 1, INT_MAX >> 1);

  memo[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    for (int j = 1; j <= i; j++) {
      memo[i] = min<int>(memo[i], arr[j] + memo[i - j]);
    }

    if (arr[i] > memo[i]) {
      cout << "NIE";
      return 0;
    }
  }

  cout << "TAK\n"
       << n << "\n";
  for (int i = 1; i <= n; i++) cout << memo[i] - memo[i - 1] << " ";

  return 0;
}
