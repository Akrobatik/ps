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
