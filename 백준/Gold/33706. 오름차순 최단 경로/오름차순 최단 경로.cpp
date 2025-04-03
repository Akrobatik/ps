#include <bits/stdc++.h>

using namespace std;

bool memo[200001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    memo[max<int>(u, v)] = true;
  }

  for (int i = 2; i <= n; i++) {
    if (memo[i]) continue;
    cout << "NO";
    return 0;
  }
  cout << "YES";

  return 0;
}
