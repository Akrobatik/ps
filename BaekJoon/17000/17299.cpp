// Title : 오등큰수
// Link  : https://www.acmicpc.net/problem/17299 
// Time  : 288 ms
// Memory: 21564 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> arr(n), brr(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr[i] = {x, 0};
    brr[i] = {x, i};
  }
  sort(brr.begin(), brr.end());

  auto it = brr.begin();
  while (it != brr.end()) {
    int x = it->first, cnt = 0;
    auto nxt = it;
    while (nxt != brr.end() && nxt->first == x) ++nxt, ++cnt;
    while (it != nxt) {
      arr[(it++)->second].second = cnt;
    }
  }

  vector<int> ans;
  ans.reserve(n);
  vector<pair<int, int>> stk;
  for (auto [x, cnt] : views::reverse(arr)) {
    while (!stk.empty() && stk.back().first <= cnt) stk.pop_back();
    ans.push_back(stk.empty() ? -1 : stk.back().second);
    stk.push_back({cnt, x});
  }

  for (auto e : views::reverse(ans)) cout << e << " ";

  return 0;
}
