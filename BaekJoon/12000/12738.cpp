// Title : 가장 긴 증가하는 부분 수열 3
// Link  : https://www.acmicpc.net/problem/12738 
// Time  : 176 ms
// Memory: 8292 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> memo;
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
  cout << memo.size();

  return 0;
}
