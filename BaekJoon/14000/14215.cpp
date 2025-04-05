// Title : 세 막대
// Link  : https://www.acmicpc.net/problem/14215
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t a, b, c;
  cin >> a >> b >> c;
  int64_t maxx = max<int64_t>({a, b, c});
  cout << min<int64_t>(a + b + c, ((a + b + c - maxx) << 1) - 1);

  return 0;
}
