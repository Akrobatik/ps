#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;
  while (n--) {
    int v;
    cin >> v;
    if (v < x) cout << v << " ";
  }

  return 0;
}
