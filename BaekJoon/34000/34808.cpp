// Title : 건조한 조건
// Link  : https://www.acmicpc.net/problem/34808 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, m, k;
  cin >> n >> m >> k;

  if (min<int64_t>(n, m) != 1) {
    cout << "-1";
    return 0;
  }

  if (max<int64_t>(n, m) > 2 && k == 0) {
    cout << "-1";
    return 0;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << k * (i + j) << " ";
    }
    cout << "\n";
  }

  return 0;
}