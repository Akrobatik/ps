// Title : 가희와 일본 문화
// Link  : https://www.acmicpc.net/problem/34666 
// Time  : 24 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, v[3];
    cin >> n;
    for (auto& e : v) cin >> e;

    int c1 = 0, c2 = 0;
    for (int i = 0; i < 2; i++) {
      c1 += (v[i] * 3 < (n == 1 ? 100 : 90));
      c2 += (v[i] <= 21);
    }
    cout << (n <= 2 && v[2] >= 50 && (c1 >= 2 || c2 >= 1) ? "YES\n" : "NO\n");
  }

  return 0;
}