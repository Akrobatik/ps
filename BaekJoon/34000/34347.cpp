// Title : 제곱수 순열$^2$
// Link  : https://www.acmicpc.net/problem/34347 
// Time  : 0 ms
// Memory: 2152 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  bool check[5001] = {};
  for (int i = 1; i * i <= 5000; i++) {
    check[i * i] = true;
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<int> orr, err;
    for (int i = 1; i <= n; i++) {
      if (i & 1) {
        orr.push_back(i);
      } else {
        err.push_back(i);
      }
    }

    bool ok = true;
    vector<int> brr(n);
    for (int i = 1; i <= n; i++) {
      if (check[i]) {
        if (!orr.empty()) {
          int x = orr.back();
          orr.pop_back();
          brr[i - 1] = x;
        } else if (!err.empty()) {
          int x = err.back();
          err.pop_back();
          brr[i - 1] = x;
        } else {
          ok = false;
          break;
        }
      } else {
        if (!err.empty()) {
          int x = err.back();
          err.pop_back();
          brr[i - 1] = x;
        } else {
          ok = false;
          break;
        }
      }
    }

    if (!ok) {
      cout << "NO\n";
      continue;
    }

    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
      cout << i << " ";
    }
    cout << "\n";
    for (auto e : brr) cout << e << " ";
    cout << "\n";
  }

  return 0;
}
