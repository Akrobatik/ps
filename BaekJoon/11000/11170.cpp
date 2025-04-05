// Title : 0의 개수
// Link  : https://www.acmicpc.net/problem/11170
// Time  : 12 ms
// Memory: 5928 KB

#include <bits/stdc++.h>

using namespace std;

int memo[1000002];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 0; i <= 1000000; i++) {
    string s = to_string(i);
    int cnt = 0;
    for (auto c : s) cnt += (c == '0');
    memo[i + 1] = memo[i] + cnt;
  }

  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    cout << memo[r + 1] - memo[l] << "\n";
  }

  return 0;
}
