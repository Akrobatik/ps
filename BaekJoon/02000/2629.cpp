// Title : 양팔저울
// Link  : https://www.acmicpc.net/problem/2629 
// Time  : 12 ms
// Memory: 11568 KB

#include <bits/stdc++.h>

using namespace std;

bitset<2400001> memo[31];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  memo[0].set(1200000);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    memo[i + 1] |= memo[i];
    memo[i + 1] |= (memo[i] << x);
    memo[i + 1] |= (memo[i] >> x);
  }

  int m;
  cin >> m;
  while (m--) {
    int x;
    cin >> x;
    cout << (memo[n].test(x + 1200000) ? "Y " : "N ");
  }

  return 0;
}
