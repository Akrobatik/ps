// Title : 스왑 스왑
// Link  : https://www.acmicpc.net/problem/34728 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> fwk(n + 1);

  auto Update = [&](int i) {
    for (; i <= n; i += i & (-i)) ++fwk[i];
  };

  auto Query = [&](int i) {
    int res = 0;
    for (; i; i -= i & (-i)) res += fwk[i];
    return res;
  };

  int64_t cnt = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt += i - Query(x);
    Update(x);
  }
  cout << ((~cnt & 1) ? "Yes" : "No");

  return 0;
}
