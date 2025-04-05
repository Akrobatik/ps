// Title : 1， 2， 3 더하기 2
// Link  : https://www.acmicpc.net/problem/12101
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int memo[11];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memo[0] = memo[1] = 1;
  memo[2] = 2;
  for (int i = 3; i <= 10; i++) {
    memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
  }

  int n, k;
  cin >> n >> k;
  if (memo[n] < k) {
    cout << "-1";
    return 0;
  }

  vector<int> ans;
  while (k > 0 && n > 0) {
    if (k <= memo[n - 1]) {
      ans.push_back(1);
      n -= 1;
      continue;
    }
    k -= memo[n - 1];
    if (k <= memo[n - 2]) {
      ans.push_back(2);
      n -= 2;
      continue;
    }
    k -= memo[n - 2];
    ans.push_back(3);
    n -= 3;
  }

  int last = ans.back();
  ans.pop_back();
  for (auto e : ans) cout << e << "+";
  cout << last;

  return 0;
}
