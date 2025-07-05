// Title : 동전 쌍 뒤집기
// Link  : https://www.acmicpc.net/problem/32034 
// Time  : 16 ms
// Memory: 9832 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> arr, stk;

  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;

    arr.clear();
    for (int i = 0; i < n; i++) {
      if (s[i] == 'T') arr.push_back(i);
    }

    int na = arr.size();
    if (na & 1) {
      cout << "-1\n";
      continue;
    }

    int64_t ans = 0;
    stk.clear();
    for (auto e : arr) {
      if (!stk.empty() && (e % 2 != stk.back() % 2)) {
        auto x = stk.back();
        stk.pop_back();
        ans += e - x;
      } else {
        stk.push_back(e);
      }
    }
    cout << (stk.empty() ? ans : -1) << "\n";
  }

  return 0;
}
