// Title : tree xor
// Link  : https://www.acmicpc.net/problem/35116 
// Time  : 8 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  if (n == 2) {
    cout << "1 2";
    return 0;
  }

  auto Print = [](int u, int v) {
    if (u > v) swap(u, v);
    cout << u + 1 << " " << v + 1 << "\n";
  };

  int half = n >> 1;
  for (int t = 1; t < n; t++) {
    for (int i = 1; i <= half; i++) Print(i, n - i);
    for (int i = 1; i <= half; i++) Print((t + i) % n, (n + t - i) % n);
  }

  return 0;
}