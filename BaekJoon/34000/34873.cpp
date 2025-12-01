// Title : 사탕 나눠주기
// Link  : https://www.acmicpc.net/problem/34873 
// Time  : 20 ms
// Memory: 2804 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int m = n << 1;

  vector<int> cnt(m + 1);
  bool ok = true;
  for (int i = 0; ok && i < m; i++) {
    int x;
    cin >> x;
    ok = (++cnt[x] <= 2);
  }
  cout << (ok ? "Yes" : "No");

  return 0;
}