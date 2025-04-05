// Title : 약수의 합
// Link  : https://www.acmicpc.net/problem/17425
// Time  : 68 ms
// Memory: 9832 KB

#include <bits/stdc++.h>

using namespace std;

int64_t memo[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 1; i <= 1000000; i++) {
    for (int j = i; j <= 1000000; j += i) memo[j] += i;
    memo[i] += memo[i - 1];
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
