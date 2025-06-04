#include <bits/stdc++.h>

using namespace std;

struct KMP {
  void Init(string_view sv) {
    int n = sv.size();
    pat = sv;
    table.clear(), table.resize(n, 0);
    int idx = 0;
    for (int i = 1; i < n; i++) {
      while (idx && sv[i] != sv[idx]) idx = table[idx - 1];
      if (sv[i] == sv[idx]) table[i] = ++idx;
    }
  }

  vector<int> Search(string_view sv) {
    vector<int> res;
    int n = sv.size(), np = table.size();
    int idx = 0;
    for (int i = 0; i < n; i++) {
      while (idx && sv[i] != pat[idx]) idx = table[idx - 1];
      if (sv[i] == pat[idx]) {
        if (++idx == np) {
          res.push_back(i - np + 1);
          idx = table[idx - 1];
        }
      }
    }
    return res;
  }

  string pat;
  vector<int> table;
};