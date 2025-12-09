// Title : 포스택
// Link  : https://www.acmicpc.net/problem/25556 
// Time  : 12 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> memo;

  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    auto it = lower_bound(memo.begin(), memo.end(), x, greater<int>());
    if (it != memo.end()) {
      *it = x;
    } else {
      memo.push_back(x);
    }
  }

  cout << (memo.size() <= 4 ? "YES" : "NO");

  return 0;
}