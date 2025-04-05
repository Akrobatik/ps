// Title : 캥거루 세마리2
// Link  : https://www.acmicpc.net/problem/11034
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t a, b, c;
  while (cin >> a >> b >> c) {
    cout << max<int64_t>(b - a, c - b) - 1 << "\n";
  }

  return 0;
}
