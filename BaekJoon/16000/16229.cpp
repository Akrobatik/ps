// Title : 반복 패턴
// Link  : https://www.acmicpc.net/problem/16229 
// Time  : 0 ms
// Memory: 2784 KB

#include <bits/stdc++.h>

using namespace std;

struct ZAlgorithm {
  void Init(string_view sv) {
    int n = sv.size();
    z.clear(), z.resize(n, 0);

    int rem = 0, cnt;
    for (int i = 1; i < n; i++) {
      auto& x = z[i];
      if (rem) x = min<int>(rem--, z[++cnt]);
      while (i + x < n && sv[i + x] == sv[x]) ++x;
      if (rem < x - 1) rem = x - 1, cnt = 0;
    }
    z[0] = n;
  }

  vector<int> z;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  string s;
  cin >> n >> k >> s;

  if (n <= k) {
    cout << n;
    return 0;
  }

  ZAlgorithm za;
  za.Init(s);
  auto& z = za.z;

  auto Check = [&](int s) {
    for (int i = s; i < n; i += s) {
      if (s - z[i] > k) return false;
      if (z[i] + i != n) return false;
    }
    return true;
  };

  int ans = n - 1;
  while (ans > 0 && !Check(ans)) --ans;
  cout << ans;

  return 0;
}