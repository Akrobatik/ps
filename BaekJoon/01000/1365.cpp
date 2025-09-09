// Title : 꼬인 전깃줄
// Link  : https://www.acmicpc.net/problem/1365 
// Time  : 8 ms
// Memory: 2532 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  
  vector<int> memo;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    auto it = lower_bound(memo.begin(), memo.end(), x);
    if (it != memo.end()) {
      *it = x;
    } else {
      memo.push_back(x);
    }
  }

  cout << n - memo.size();

  return 0;
}