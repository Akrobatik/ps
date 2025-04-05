// Title : ACM 대회 채점
// Link  : https://www.acmicpc.net/problem/11531
// Time  : 0 ms
// Memory: 2028 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  unordered_map<string, int> hm;
  int64_t m;
  string name, result;
  int64_t a1 = 0, a2 = 0;
  while (cin >> m >> name >> result) {
    auto& x = hm[name];
    if (x == -1) continue;
    if (result == "right") {
      ++a1;
      a2 += m + x * 20;
      x = -1;
    } else {
      ++x;
    }
  }
  cout << a1 << " " << a2;

  return 0;
}
