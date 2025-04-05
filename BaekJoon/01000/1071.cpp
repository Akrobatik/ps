// Title : 소트
// Link  : https://www.acmicpc.net/problem/1071 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end());

  vector<int> ans;
  ans.push_back(arr[0]);
  arr.erase(arr.begin());
  while (!arr.empty()) {
    int nr = arr.size();
    auto it = arr.begin();
    while (it != arr.end() && *it == ans.back() + 1) ++it;

    if (it != arr.end()) {
      ans.push_back(*it);
      arr.erase(it);
      continue;
    }

    auto rit = ans.rbegin();
    while (rit != ans.rend() && *rit == ans.back()) ++rit;
    it = rit.base();
    for (auto e : ranges::subrange(ans.begin(), it)) cout << e << " ";
    for (auto e : arr) cout << e << " ";
    for (auto e : ranges::subrange(it, ans.end())) cout << e << " ";
    return 0;
  }
  for (auto e : ans) cout << e << " ";

  return 0;
}
