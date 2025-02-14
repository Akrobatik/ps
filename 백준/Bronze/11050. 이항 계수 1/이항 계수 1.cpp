#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, r;
  cin >> n >> r;
  if (r > n - r) r = n - r;
  int v = 1;
  for (int i = 0; i < r; i++) {
    v *= n - i;
    v /= i + 1;
  }
  cout << v;

  return 0;
}
