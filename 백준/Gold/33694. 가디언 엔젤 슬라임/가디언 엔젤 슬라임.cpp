#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;
  vector<pair<int64_t, int64_t>> arr;
  arr.reserve(n);
  for (int i = 0; i < n; i++) {
    int64_t a, b, c, t;
    cin >> a >> b >> c >> t;
    int64_t s = (x + a - 1) / a;
    int64_t m = (c + a - 1) / a;
    int64_t e = m + (m * a - x) / b;
    if (s <= e) arr.push_back({s + t, e + t});
  }
  sort(arr.begin(), arr.end());

  priority_queue<int64_t> maxpq;
  priority_queue<int64_t, vector<int64_t>, greater<>> minpq;
  int64_t ans = 0, r = 0;
  for (auto [s, e] : arr) {
    while (!minpq.empty() && minpq.top() < s) minpq.pop();
    minpq.push(e), maxpq.push(e);
    if (minpq.size() >= 3) {
      int64_t e1 = maxpq.top();
      maxpq.pop();
      int64_t e2 = maxpq.top();
      maxpq.pop();
      ans += max<int64_t>(maxpq.top() - max<int64_t>(s, r) + 1, 0);
      r = max<int64_t>(r, maxpq.top() + 1);
      maxpq.push(e2);
      maxpq.push(e1);
    }
  }
  cout << ans;

  return 0;
}
