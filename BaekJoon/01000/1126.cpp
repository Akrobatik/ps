// Title : 같은 탑
// Link  : https://www.acmicpc.net/problem/1126 
// Time  : 48 ms
// Memory: 5928 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 500000;

int _memo[2][kMax + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  auto memo = _memo[0], mnxt = _memo[1];

  auto Update = [&](int l, int r) {
    mnxt[l - r] = max<int>(mnxt[l - r], l);
  };

  int n, sum = 0;
  cin >> n;
  while (n--) {
    memcpy(mnxt, memo, (sum + 1) * sizeof(int));

    int x;
    cin >> x;
    for (int i = 0; i <= sum; i++) {
      if (i && memo[i] == 0) continue;
      int l = memo[i], r = l - i;
      Update(l + x, r);
      r += x;
      if (l < r) swap(l, r);
      Update(l, r);
    }

    sum += x;
    swap(memo, mnxt);
  }

  cout << (memo[0] ? memo[0] : -1);

  return 0;
}
