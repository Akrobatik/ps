// Title : 억지부리기
// Link  : https://www.acmicpc.net/problem/34893 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t u, o, s;
  cin >> u >> o >> s;

  int64_t ru = u - s;
  if (ru > 0) {
    int64_t cut = ru / 3;
    u -= cut << 1, s += cut;
  }
  cout << min<int64_t>({u, o, s});

  return 0;
}