// Title : 반도체 설계
// Link  : https://www.acmicpc.net/problem/2352 
// Time  : 4 ms
// Memory: 2532 KB

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