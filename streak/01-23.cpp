// https://www.acmicpc.net/problem/35164

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> qr(m);
  for (auto& e : qr) cin >> e;

  int all = (count(qr.begin(), qr.end(), qr[0]) == m);
  if (n == 2) {
    if (count(qr.begin(), qr.end(), qr[0]) == m) {
      int add = 1 - qr[0];
      cout << "1\n"
           << "1 0 2\n"
           << "1 " << 1 + add << " " << 3 + add << "\n";
      for (int i = 0; i < m; i++) {
        cout << "2 1 2\n";
      }
    } else {
      cout << "-1";
    }
    return 0;
  }

  cout << "1\n";
  for (int i = 0; i < n; i++) {
    int add = (i < 2 ? 0 : 1);
    cout << "1 " << i + add << " " << i + add + 2 << "\n";
  }
  for (int i = 0; i < m; i++) {
    cout << "2 1 " << 3 - qr[i] << "\n";
  }

  return 0;
}