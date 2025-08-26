// Title : 문자열과 쿼리
// Link  : https://www.acmicpc.net/problem/13713 
// Time  : 28 ms
// Memory: 7076 KB

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

  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  int n = s.size();

  ZAlgorithm za;
  za.Init(s);

  int m;
  cin >> m;
  while (m--) {
    int x;
    cin >> x;
    cout << za.z[n - x] << "\n";
  }

  return 0;
}
