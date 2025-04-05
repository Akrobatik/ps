// Title : ACM 호텔
// Link  : https://www.acmicpc.net/problem/10250
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
    int h, w, n;
    cin >> h >> w >> n;
    --n;
    int y = (n % h) + 1;
    int x = (n / h) + 1;
    cout << y << setw(2) << setfill('0') << x << "\n";
  }

  return 0;
}
