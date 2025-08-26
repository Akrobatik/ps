// Title : 스카이라인 쉬운거
// Link  : https://www.acmicpc.net/problem/1863 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int cnt = 0;
  vector<int> stk;
  while (n--) {
    int x;
    cin >> x >> x;
    while (!stk.empty() && stk.back() > x) stk.pop_back(), ++cnt;
    if (x == 0 || (!stk.empty() && stk.back() == x)) continue;
    stk.push_back(x);
  }

  cout << cnt + stk.size();

  return 0;
}
