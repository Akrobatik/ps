// Title : 오큰수
// Link  : https://www.acmicpc.net/problem/17298 
// Time  : 196 ms
// Memory: 16108 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  vector<int> ans, memo;
  ans.reserve(n);
  for (auto x : views::reverse(arr)) {
    while (!memo.empty() && memo.back() <= x) memo.pop_back();
    ans.push_back(memo.empty() ? -1 : memo.back());
    memo.push_back(x);
  }

  for (auto e : views::reverse(ans)) cout << e << " ";

  return 0;
}
