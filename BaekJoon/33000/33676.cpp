// Title : 우주 여행
// Link  : https://www.acmicpc.net/problem/33676
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k, l;
  cin >> n >> m >> k >> l;

  if (n + m - 2 > l || ((n + m - l) & 1)) {
    cout << "-1";
    return 0;
  }

  int lm = l - (n + m - 2);
  for (int i = 0; i < lm; i += 2) {
    cout << "DU";
  }
  for (int i = 1; i < n; i++) {
    cout << "D";
  }
  for (int i = 1; i < m; i++) {
    cout << "R";
  }

  return 0;
}