// Title : Parliament
// Link  : https://www.acmicpc.net/problem/7444 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> ans;
  for (int i = 2; i <= n; i++) {
    ans.push_back(i);
    n -= i;
  }

  int na = ans.size();
  while (n > 0) {
    for (int i = 0; i < min<int>(na, n); i++) {
      ++ans[na - i - 1];
    }
    n -= na;
  }

  for (auto e : ans) cout << e << " ";

  return 0;
}