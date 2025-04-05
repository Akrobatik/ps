#include <bits/stdc++.h>

using namespace std;

bool memo[42];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int ans = 0;
  for (int i = 0; i < 10; i++) {
    int v;
    cin >> v;
    int rem = v % 42;
    if (memo[rem]) continue;
    memo[rem] = true;
    ++ans;
  }
  cout << ans;

  return 0;
}
