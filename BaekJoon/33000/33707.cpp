// Title : 젓가락으로 메추리알 집기
// Link  : https://www.acmicpc.net/problem/33707
// Time  : 264 ms
// Memory: 30264 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((i + j) & 1) {
        cout << "? " << i + 1 << " " << j + 1 << endl;
        int x;
        cin >> x;
        if (x == 1) {
          return 0;
        }
      }
    }
  }

  return 0;
}
