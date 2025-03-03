#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int k;
  cin >> k;
  int n = (1 << k) - 1;
  vector<vector<int>> memo(k);
  for (uint32_t i = 1; i <= n; i++) {
    int x;
    cin >> x;
    memo[k - countr_zero(i) - 1].push_back(x);
  }

  for (auto& e : memo) {
    for (auto x : e) {
      cout << x << " ";
    }
    cout << "\n";
  }

  return 0;
}
