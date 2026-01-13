// Title : 자르기
// Link  : https://www.acmicpc.net/problem/35113 
// Time  : 172 ms
// Memory: 26160 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kInf = INT_MAX >> 1;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  vector<pair<int, int>> stk;
  vector<int> memo(n + 1, kInf), mnxt;
  memo[0] = 0;
  for (int t = 0; t < 4; t++) {
    mnxt.assign(n + 1, kInf);
    for (int i = 1; i <= n; i++) {
      int val = memo[i - 1];

      while (!stk.empty() && arr[stk.back().first] <= arr[i]) {
        val = min<int>(val, stk.back().second);
        stk.pop_back();
      }
      mnxt[i] = min<int>({mnxt[i], val + arr[i], !stk.empty() ? mnxt[stk.back().first] : kInf});
      stk.push_back({i, val});
    }
    swap(memo, mnxt);
    stk.clear();
  }
  cout << memo[n];

  return 0;
}