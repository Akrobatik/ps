// Title : 하이퍼 가지 따기
// Link  : https://www.acmicpc.net/problem/27941
// Time  : 4 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int ans[11] = {};
  for (int i = 0; i < 2047; i++) {
    for (int j = 0; j < 11; j++) {
      int v;
      cin >> v;
      ans[j] ^= v;
    }
  }

  for (int i = 0; i < 11; i++) cout << ans[i] << " ";

  return 0;
}
