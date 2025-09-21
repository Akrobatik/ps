// Title : x와 배수와 XOR (Easy)
// Link  : https://www.acmicpc.net/problem/34406 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kTable[2] = {1 << 30 | 1, 1 << 30};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int64_t x;
    cin >> x;

    int n = x ? 2 : 1;
    cout << n << "\n";
    while (n--) cout << kTable[n] << " ";
    cout << "\n";
  }

  return 0;
}