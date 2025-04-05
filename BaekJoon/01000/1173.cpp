// Title : 운동
// Link  : https://www.acmicpc.net/problem/1173
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, M, T, R;
  cin >> n >> m >> M >> T >> R;

  if (M - m < T) {
    cout << "-1";
    return 0;
  }

  int cur = m, t = 0;
  for (;;) {
    ++t;
    if (cur + T <= M) {
      if (--n == 0) {
        cout << t;
        return 0;
      }
      cur += T;
    } else {
      cur = max<int>(cur - R, m);
    }
  }

  return 0;
}
