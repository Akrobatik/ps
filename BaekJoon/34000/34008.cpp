// Title : 아즈모스 협곡 탐험
// Link  : https://www.acmicpc.net/problem/34008 
// Time  : 324 ms
// Memory: 9948 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  int limit = min<int>(k - 1, n << 1);

  vector<int> axr(n), bxr(n);
  for (auto& e : axr) cin >> e;
  for (auto& e : bxr) cin >> e;

  int64_t base = 0;
  vector<int> arr(n), brr(n);
  for (auto& e : arr) cin >> e;
  for (int i = 0, x; i <= n; i++) cin >> x, base += x;
  for (auto& e : brr) cin >> e;

  for (int i = 0; i < n; i++) {
    if (axr[i] > bxr[i]) swap(arr[i], brr[i]);
    if (axr[i] == bxr[i]) {
      if (axr[i] == 1) {
        arr[i] = max<int>(arr[i], brr[i]);
        brr[i] = 0;
      } else {
        brr[i] = max<int>(arr[i], brr[i]);
        arr[i] = 0;
      }
    } else {
      brr[i] = max<int>(brr[i] - arr[i], 0);
    }
  }

  vector<bool> memo(n);

  auto GetValue = [&](int i) {
    if (memo[i]) return brr[i] << 1;
    return max<int>(arr[i] + brr[i], arr[i] << 1);
  };

  auto Cmp = [&](int lhs, int rhs) {
    int lv = GetValue(lhs), rv = GetValue(rhs);
    return lv < rv || (lv == rv && !memo[lhs]);
  };

  priority_queue<int, vector<int>, decltype(Cmp)> pq(Cmp);
  for (int i = 0; i < n; i++) {
    pq.push(i);
  }

  int minn = 1e9;
  int64_t add = 0;
  while (limit > 1) {
    int x = pq.top();
    pq.pop();

    if (memo[x]) {
      --limit;
      add += brr[x];
      minn = min<int>(minn, brr[x]);
    } else if (GetValue(x) == arr[x] + brr[x]) {
      limit -= 2;
      add += arr[x] + brr[x];
      minn = min<int>(minn, brr[x]);
      memo[x] = true;
    } else {
      --limit;
      add += arr[x];
      minn = min<int>(minn, arr[x]);
      memo[x] = true;
      pq.push(x);
    }
  }

  if (limit) {
    int one = 0, two = 0;
    while (!pq.empty()) {
      int x = pq.top();
      pq.pop();

      if (memo[x]) {
        one = max<int>(one, brr[x]);
      } else {
        one = max<int>(one, arr[x]);
        two = max<int>(two, arr[x] + brr[x]);
      }
    }
    add += max<int>(one, two - minn);
  }

  cout << base + add;

  return 0;
}
