// Title : 탑
// Link  : https://www.acmicpc.net/problem/2493 
// Time  : 88 ms
// Memory: 7176 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  vector<int> stk;
  for (int i = 0; i < n; i++) {
    while (!stk.empty() && arr[stk.back()] < arr[i]) stk.pop_back();
    cout << (stk.empty() ? 0 : stk.back() + 1) << " ";
    stk.push_back(i);
  }

  return 0;
}
