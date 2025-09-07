// Title : 진짜 금화 찾기
// Link  : https://www.acmicpc.net/problem/34219 
// Time  : 4 ms
// Memory: 13676 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> cands, query(n + 1);
  vector<bool> out(n + 1);

  for (;;) {
    cands.clear();
    int64_t exp = 0;
    for (int i = 1, j = 0; i <= n; i++) {
      if (out[i]) {
        query[i] = 0;
      } else {
        cands.push_back(i);
        query[i] = j++ % 6;
        exp += query[i] * 9;
      }
    }

    if (cands.size() == 1) break;

    cout << "?";
    for (int i = 1; i <= n; i++) {
      cout << " " << query[i];
    }
    cout << endl;

    int64_t cur;
    cin >> cur;

    int delta = cur - exp;
    for (auto e : cands) {
      if (query[e] == delta) continue;
      out[e] = true;
    }
  }

  cout << "! " << cands[0] << endl;

  return 0;
}
