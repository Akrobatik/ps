// Title : 스트레칭
// Link  : https://www.acmicpc.net/problem/33812 
// Time  : 408 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, r;
  cin >> n >> k >> r;

  bitset<100000> memo;
  for (int i = 0; i < n; i++) memo.set(i);

  while (r--) {
    bitset<100000> mask;
    for (int i = 0; i < k; i++) {
      int x;
      cin >> x;
      mask.set(x - 1);
    }

    string s;
    cin >> s;
    if (s == "satisfied") mask = ~mask;
    memo &= mask;
  }

  int cnt = memo.count(), ans = 0;
  if (cnt > k * 2) {
    int t = (cnt - k - 1) / k;
    cnt -= k * t;
    ans += t;
  }

  while (cnt > 1) {
    cnt = cnt - min<int>(cnt >> 1, n - k);
    ++ans;
  }
  cout << ans;

  return 0;
}
