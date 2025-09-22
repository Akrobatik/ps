// Title : 작은 수는 싫어!
// Link  : https://www.acmicpc.net/problem/34405 
// Time  : 1048 ms
// Memory: 138756 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int64_t> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    arr[i] = arr[i - 1] + x;
  }

  map<int, int64_t, greater<int>> m1;
  map<int64_t, int, greater<int64_t>> m2;

  auto Push = [&](int cnt, int64_t val) {
    auto it = m1.lower_bound(cnt);
    if (it != m1.end() && it->first == cnt) {
      if (it->second <= val) return;
      m2.erase(it->second);
      it = m1.erase(it);
    }

    if (it != m1.begin()) {
      auto lit = prev(it);
      if (lit->second <= val) return;
    }

    while (it != m1.end() && it->second >= val) {
      m2.erase(it->second);
      it = m1.erase(it);
    }

    m1[cnt] = val;
    m2[val] = cnt;
  };

  Push(0, 0);

  vector<int> memo(n + 1);
  for (int i = 1; i <= n; i++) {
    auto it = m2.lower_bound(arr[i] - k);
    if (it != m2.end()) {
      memo[i] = it->second + 1;
      Push(memo[i], arr[i]);
    } else {
      Push(0, arr[i]);
    }
  }
  cout << *max_element(memo.begin(), memo.end());

  return 0;
}