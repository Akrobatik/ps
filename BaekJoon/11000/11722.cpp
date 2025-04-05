// Title : 가장 긴 감소하는 부분 수열
// Link  : https://www.acmicpc.net/problem/11722
// Time  : 0 ms
// Memory: 2020 KB

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
