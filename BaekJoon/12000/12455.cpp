// Title : 最高のコーヒー (Small)
// Link  : https://www.acmicpc.net/problem/12455 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int64_t, int64_t, int64_t>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int64_t n, k;
    cin >> n >> k;
    vector<tup> arr(n);
    for (auto& [o, c, s] : arr) cin >> c >> o >> s;
    sort(arr.begin(), arr.end());

    int64_t sum = 0, cnt = 0;
    priority_queue<pair<int64_t, int64_t>, vector<pair<int64_t, int64_t>>, greater<pair<int64_t, int64_t>>> pq;
    for (auto [o, c, s] : arr) {
      pq.push({s, c});
      sum += s * c, cnt += c;
      while (cnt > o) {
        auto [ss, cc] = pq.top();
        pq.pop();

        int64_t cut = min<int64_t>(cc, cnt - o);
        sum -= ss * cut, cnt -= cut;
        if ((cc -= cut) != 0) pq.push({ss, cc});
      }
    }
    cout << "Case #" << tc << ": " << sum << "\n";
  }

  return 0;
}
