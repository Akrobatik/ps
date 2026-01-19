// Title : 포켓몬 마스터 이민재
// Link  : https://www.acmicpc.net/problem/35151 
// Time  : 8 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string ans;

  int t;
  cin >> t;
  while (t--) {
    int64_t r, maxx, f;
    cin >> r >> maxx >> f;
    int64_t cur = maxx;

    int64_t bnd = maxx * 1530;

    auto Calc = [&](int64_t x, int64_t y) {
      return (maxx * 3 - x * 2) * r * y;
    };

    ans.clear();
    for (;;) {
      if (Calc(cur, 2) >= bnd) {
        ans.push_back('C');
        break;
      }

      if (Calc(cur, 3) >= bnd) {
        ans.push_back('G');
        ans.push_back('C');
        break;
      }

      if (Calc(max<int64_t>(cur - f, 1), 2) >= bnd) {
        ans.push_back('F');
        ans.push_back('C');
        break;
      }

      if (Calc(max<int64_t>(cur - f, 1), 5) >= bnd) {
        ans.push_back('Y');
        ans.push_back('F');
        ans.push_back('C');
        break;
      }

      if (cur == 1) {
        if (Calc(cur, 3) >= bnd) {
          ans.push_back('G');
          ans.push_back('C');
        } else {
          ans.push_back('Y');
          ans.push_back('F');
          ans.push_back('C');
        }
        break;
      }

      cur = max<int64_t>(cur - f, 1);
      if (cur == 1) {
        ans.push_back('Y');
        ans.push_back('F');
        ans.push_back('C');
        break;
      }

      ans.push_back('F');
    }
    cout << ans << "\n";
  }

  return 0;
}