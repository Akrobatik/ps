// Title : 파일 탐색기
// Link  : https://www.acmicpc.net/problem/20210 
// Time  : 84 ms
// Memory: 42536 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<string>> arr(n);
  for (auto& vec : arr) {
    string s;
    cin >> s;

    int idx = 0, ns = s.size();
    while (idx < ns) {
      if (s[idx] >= 'A') {
        bool cap = (s[idx] < 'a');
        int ord = s[idx] - 'A' - (cap ? 0 : 32);
        vec.push_back(string(1, 'A' + ord * 2 + (cap ? 0 : 1)));

        ++idx;
        continue;
      }

      int nxt = idx;
      while (nxt < ns && s[nxt] <= '9') ++nxt;
      vec.push_back(s.substr(idx, nxt - idx));
      idx = nxt;
    }
  }

  sort(arr.begin(), arr.end(), [&](const vector<string>& lhs, const vector<string>& rhs) {
    int nl = lhs.size(), nr = rhs.size();
    int minn = min<int>(nl, nr);
    for (int i = 0; i < minn; i++) {
      if (lhs[i][0] > '9' || rhs[i][0] > '9') {
        int cmp = lhs[i].compare(rhs[i]);
        if (cmp == 0) continue;
        return cmp < 0;
      }

      string_view lv = lhs[i], rv = rhs[i];
      while (!lv.empty() && lv[0] == '0') lv = lv.substr(1);
      while (!rv.empty() && rv[0] == '0') rv = rv.substr(1);
      if (lv.size() != rv.size()) return lv.size() < rv.size();

      int cmp = lv.compare(rv);
      if (cmp == 0) {
        if (lhs[i].size() == rhs[i].size()) continue;
        return lhs[i].size() < rhs[i].size();
      }
      return cmp < 0;
    }
    return nl < nr;
  });

  for (auto& vec : arr) {
    for (auto& s : vec) {
      if (s[0] <= '9') {
        cout << s;
      } else {
        int x = s[0] - 'A';
        int ord = x >> 1, cap = (~x & 1);
        cout << (char)('A' + ord + (cap ? 0 : 32));
      }
    }
    cout << "\n";
  }

  return 0;
}