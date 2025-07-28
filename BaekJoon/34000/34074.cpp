// Title : 리오와 리쿠의 대난투
// Link  : https://www.acmicpc.net/problem/34074 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  if (n == 1 && m == 1) {
    cout << "-1";
    return 0;
  }

  int64_t x = kMax >> 1;
  vector<int> arr(n), brr(m);
  if (n == 1) {
    cout << x << "\n"
         << "1 ";
    for (int i = 1; i < m; i++) cout << x + i << " ";
  } else {
    for (int i = 1; i < n; i++) cout << i << " ";
    cout << x << "\n";
    for (int i = 0; i < m; i++) cout << n + i << " ";
  }

  return 0;
}
