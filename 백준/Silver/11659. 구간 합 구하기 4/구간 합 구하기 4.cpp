#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int psum[100001];
  psum[0] = 0;

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int v;
    cin >> v;
    psum[i] = psum[i - 1] + v;
  }

  while (m--) {
    int i, j;
    cin >> i >> j;
    cout << psum[j] - psum[i - 1] << "\n";
  }

  return 0;
}
