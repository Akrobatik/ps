// Title : 주식
// Link  : https://www.acmicpc.net/problem/12014 
// Time  : 24 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> memo;

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int n, k;
    cin >> n >> k;

    memo.clear();
    while (n--) {
      int x;
      cin >> x;
      auto it = lower_bound(memo.begin(), memo.end(), x);
      if (it != memo.end()) {
        *it = x;
      } else {
        memo.push_back(x);
      }
    }
    cout << "Case #" << tc << "\n"
         << (k <= memo.size()) << "\n";
  }

  return 0;
}
