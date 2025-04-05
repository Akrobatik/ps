// Title : 줄 세우기
// Link  : https://www.acmicpc.net/problem/1681
// Time  : 28 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, l;
  cin >> n >> l;

  int cnt = 0;
  for (int i = 1;; i++) {
    string s = to_string(i);
    bool ok = true;
    for (auto c : s) {
      if (c == l + '0') {
        ok = false;
        break;
      }
    }

    if (ok && ++cnt == n) {
      cout << i;
      return 0;
    }
  }

  return 0;
}
