// Title : 가위바위보
// Link  : https://www.acmicpc.net/problem/34623 
// Time  : 48 ms
// Memory: 15976 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto Id = [&](char c) {
    if (c == 'R') return 0;
    if (c == 'S') return 1;
    return 2;
  };

  vector<pair<int, int>> arr;

  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;

    int cnts[3] = {};

    int idx = 0;
    arr.clear();
    while (idx < n) {
      int nxt = idx;
      while (nxt < n && s[idx] == s[nxt]) ++nxt;

      int id = Id(s[idx]);
      cnts[id] += nxt - idx;
      arr.push_back({Id(s[idx]), nxt - idx});
      idx = nxt;
    }
    int na = arr.size();

    for (int o = 0; o < 3; o++) {
      int x = o, y = (o + 1) % 3, z = (o + 2) % 3;

      if (cnts[x] == 0 || (cnts[y] == 0 && cnts[z] > 0)) {
        cout << "-1 ";
        continue;
      }

      if (cnts[x] == n) {
        cout << "0 ";
        continue;
      }

      bool first = true;
      int st = (arr[0].first == x ? 1 : 0);
      int en = (arr[na - 1].first == x ? na - 2 : na - 1);
      int cut = 0, sum = 0, maxx = 0, on = 0;
      for (int i = st; i <= en; i++) {
        auto [type, sz] = arr[i];
        if (type == x) {
          sum += sz, maxx = max<int>(maxx, sz);
        } else if (type == y) {
          if (on) cut += sum - (first ? 0 : maxx);
          sum = maxx = on = 0;
          first = false;
        } else {
          on = 1;
        }
      }
      if (on) cut += sum;

      cout << (cnts[x] != cut ? cut * 3 + cnts[y] + cnts[z] * 2 : -1) << " ";
    }
    cout << "\n";
  }

  return 0;
}