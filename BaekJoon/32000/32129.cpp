// Title : 마법 구슬
// Link  : https://www.acmicpc.net/problem/32129 
// Time  : 128 ms
// Memory: 5932 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  vector<int> axr(n);
  for (int i = 1; i < n; i++) axr[i] = arr[i] + i;

  int w = 1;
  int64_t val = arr[0], sum = arr[0];
  while (w < n && axr[w] <= val) sum += arr[w++];
  int64_t nxt = (((val << 1) - w + 3) * w) >> 1;
  while (m--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int x;
      cin >> x;
      while (x) {
        if (w == n) {
          int64_t cut = min<int64_t>(x, nxt - sum);
          x -= cut, sum += cut;
          if (sum == nxt) {
            val += x / n + 1;
            nxt = (((val << 1) - w + 3) * w) >> 1;
            sum += x;
            x = 0;
          }
        } else {
          int64_t cut = min<int64_t>(x, nxt - sum);
          x -= cut, sum += cut;
          if (sum == nxt) {
            ++val;
            while (w < n && axr[w] <= val) sum += arr[w++];
            nxt = (((val << 1) - w + 3) * w) >> 1;
          }
        }
      }
    } else {
      cout << val << "\n";
    }
  }

  return 0;
}
