// Title : 옥상 정원 꾸미기
// Link  : https://www.acmicpc.net/problem/6198 
// Time  : 8 ms
// Memory: 2916 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> stk;
  int64_t ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    while (!stk.empty() && stk.back() <= x) stk.pop_back();
    ans += stk.size();
    stk.push_back(x);
  }
  cout << ans;

  return 0;
}