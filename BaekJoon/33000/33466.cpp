// Title : 피타고라스 정리의 증명
// Link  : https://www.acmicpc.net/problem/33466
// Time  : 352 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int64_t n;
    cin >> n;
    cout << n + ((n >> 1) << 1) << "\n";
  }

  return 0;
}
