// Title : 도미노 예측
// Link  : https://www.acmicpc.net/problem/17943 
// Time  : 68 ms
// Memory: 2804 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  vector<int> arr(n);
  for (int i = 1; i < n; i++) {
    cin >> arr[i];
    arr[i] ^= arr[i - 1];
  }

  while (q--) {
    int cmd;
    cin >> cmd;
    if (cmd == 0) {
      int x, y;
      cin >> x >> y;
      int key = arr[x - 1] ^ arr[y - 1];
      cout << key << "\n";
    } else {
      int x, y, d;
      cin >> x >> y >> d;
      int key = arr[x - 1] ^ arr[y - 1];
      cout << (key ^ d) << "\n";
    }
  }

  return 0;
}
