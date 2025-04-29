// Title : 자기복제수
// Link  : https://www.acmicpc.net/problem/2028 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    auto s1 = to_string(n), s2 = to_string(n * n);
    auto rit1 = s1.rbegin(), rit2 = s2.rbegin();
    bool ok = true;
    for (int i = 0; ok && i < s1.size(); i++) {
      ok = (rit1[i] == rit2[i]);
    }
    cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}
