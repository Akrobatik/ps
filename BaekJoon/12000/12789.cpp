// Title : 도키도키 간식드리미
// Link  : https://www.acmicpc.net/problem/12789 
// Time  : 0 ms
// Memory: 2152 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n), stk;
  for (auto& e : arr) cin >> e;

  for (int i = 1, j = 0; i <= n; i++) {
    if (!stk.empty() && stk.back() == i) {
      stk.pop_back();
      continue;
    }
    while (j < n && arr[j] != i) stk.push_back(arr[j++]);
    ++j;
  }

  cout << (stk.empty() ? "Nice" : "Sad");

  return 0;
}