#include <bits/stdc++.h>

using namespace std;

bitset<51> party[50];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m >> n;
  bitset<51> b1, b2;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    b1.set(v, true);
  }

  for (int i = 0; i < m; i++) {
    cin >> n;
    auto& b = party[i];
    for (int j = 0; j < n; j++) {
      int v;
      cin >> v;
      b.set(v, true);
    }
  }

  do {
    b2 = b1;
    for (int i = 0; i < m; i++) {
      auto& b = party[i];
      if ((b & b1).any()) b1 |= b;
    }
  } while (b1 != b2);

  int ans = 0;
  for (int i = 0; i < m; i++) {
    party[i] &= b1;
    if (party[i].none()) ans++;
  }

  cout << ans << endl;

  return 0;
}
