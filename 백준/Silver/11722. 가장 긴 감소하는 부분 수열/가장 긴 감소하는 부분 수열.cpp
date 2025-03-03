#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> table;
  table.reserve(n);
  while (n--) {
    int x;
    cin >> x;
    auto it = lower_bound(table.begin(), table.end(), x, greater<>());
    if (it == table.end()) {
      table.push_back(x);
    } else {
      *it = x;
    }
  }
  cout << table.size();

  return 0;
}
