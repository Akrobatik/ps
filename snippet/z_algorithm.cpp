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
  }

  vector<int> z;
};