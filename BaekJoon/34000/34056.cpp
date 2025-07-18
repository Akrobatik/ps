// Title : 콘서트
// Link  : https://www.acmicpc.net/problem/34056 
// Time  : 84 ms
// Memory: 3584 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int64_t> arr(n + 1);
  for (int i = 1; i <= n; i++) cin >> arr[i];

  int q;
  cin >> q;
  while (q--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int c, x;
      cin >> c >> x;
      for (int i = c, r = x; r > 0 && i > 0; i--) {
        int cut = min<int64_t>(arr[i], r);
        arr[i] += cut;
        r -= cut;
      }
      for (int i = c + 1, r = x; r > 0 && i <= n; i++) {
        int cut = min<int64_t>(arr[i], r);
        arr[i] += cut;
        r -= cut;
      }
    } else {
      int c;
      cin >> c;
      cout << arr[c] << "\n";
    }
  }

  return 0;
}
