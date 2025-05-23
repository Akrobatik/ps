// Title : 찾기
// Link  : https://www.acmicpc.net/problem/1786
// Time  : 52 ms
// Memory: 9924 KB

#include <bits/stdc++.h>

using namespace std;

struct KMP {
  void Init(string_view sv) {
    int n = sv.size();
    pat = string(sv.begin(), sv.end());
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  KMP kmp;

  string s, p;
  getline(cin, s);
  getline(cin, p);
  kmp.Init(p);
  auto res = kmp.Search(s);
  cout << res.size() << "\n";
  for (auto i : res) cout << i + 1 << "\n";

  return 0;
}