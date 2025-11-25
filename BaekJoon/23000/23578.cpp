// Title : 비 오는 날
// Link  : https://www.acmicpc.net/problem/23578 
// Time  : 152 ms
// Memory: 9912 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  if (n == 1) {
    cout << "0";
    return 0;
  }

  vector<int64_t> arr(n + 1);
  vector<int64_t> cnt(n + 1, 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  auto Cmp = [&](int lhs, int rhs) {
    int64_t lv = arr[lhs] * (cnt[lhs] * 2 + 1), rv = arr[rhs] * (cnt[rhs] * 2 + 1);
    return lv > rv;
  };

  priority_queue<int, vector<int>, decltype(Cmp)> pq(Cmp);
  for (int i = 1; i <= n; i++) pq.push(i);

  int rem = n - 2;
  while (rem--) {
    int x = pq.top();
    pq.pop();

    ++cnt[x];
    pq.push(x);
  }

  int64_t sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += arr[i] * cnt[i] * cnt[i];
  }
  cout << sum;

  return 0;
}