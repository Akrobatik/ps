// Title : 개미와 비트코인
// Link  : https://www.acmicpc.net/problem/31574 
// Time  : 24 ms
// Memory: 3588 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, char, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, l, t;
  cin >> n >> l >> t;
  vector<tup> arr(n);
  for (int i = 0; i < n; i++) {
    int p;
    char d;
    cin >> p >> d;
    arr[i] = {p, d, i};
  }
  sort(arr.begin(), arr.end());

  int st;
  cin >> st;
  --st;

  vector<int> pos(n);
  int cycle = l << 1, spos;
  for (int i = 0; i < n; i++) {
    auto [p, d, idx] = arr[i];
    p += (d == 'L' ? -t : t);
    if ((p %= cycle) < 0) p += cycle;
    pos[i] = (p <= l ? p : cycle - p);
    if (st == idx) spos = pos[i];
  }
  sort(pos.begin(), pos.end());
  int idx = lower_bound(pos.begin(), pos.end(), spos) - pos.begin();
  cout << get<2>(arr[idx]) + 1;

  return 0;
}
