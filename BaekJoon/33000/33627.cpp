// Title : 네모네모
// Link  : https://www.acmicpc.net/problem/33627 
// Time  : 184 ms
// Memory: 33284 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, m, k;
  cin >> n >> m >> k;

  vector<int64_t> arr(n);
  for (auto& e : arr) cin >> e;

  vector<int64_t> brr(k);
  for (auto& e : brr) cin >> e;

  auto Check = [&](int i, int64_t s, int64_t e) {
    int64_t x = brr[i];
    return s <= x && x <= e;
  };

  vector<int64_t> fwd(n);
  int64_t st = 1;
  for (int i = 0, j = 0; i < n; i++) {
    int64_t len = arr[i];
    while (j < k && Check(j, st, st + len - 1)) st = brr[j++] + 1;
    fwd[i] = st;
    st += len;
  }

  vector<int64_t> bwd(n);
  int64_t en = m;
  for (int i = n - 1, j = k - 1; i >= 0; i--) {
    int64_t len = arr[i];
    while (j >= 0 && Check(j, en - len + 1, en)) en = brr[j--] - 1;
    bwd[i] = en - len + 1;
    en -= len;
  }

  auto Calc = [&](int64_t s1, int64_t e1, int64_t s2, int64_t e2) -> int64_t {
    int64_t s = max<int64_t>(s1, s2);
    int64_t e = min<int64_t>(e1, e2);
    return (s <= e ? e - s + 1 : 0);
  };

  int64_t cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += Calc(fwd[i], fwd[i] + arr[i] - 1, bwd[i], bwd[i] + arr[i] - 1);
  }
  cout << cnt;

  return 0;
}