// Title : 쿠의 용돈 인상 계획
// Link  : https://www.acmicpc.net/problem/34766 
// Time  : 16 ms
// Memory: 8464 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, d;
    string s;
    cin >> n >> d >> s;

    int x = *max_element(s.begin(), s.end()) - '0';
    if (x <= 1) {
      --d;
      s[0] = '9';
    }

    list<int> ls;
    for (auto c : views::reverse(s)) {
      ls.push_back(c - '0');
    }

    auto it = ls.begin();
    while (*it <= 1) ++it;

    while (d--) {
      int v = (*it) * 9;
      int lv = v / 10, rv = v % 10;
      *it = lv;
      it = ls.insert(it, rv);
      while (*it <= 1) ++it;
    }

    for (auto v : views::reverse(ls)) {
      cout << v;
    }
    cout << "\n";
  }

  return 0;
}