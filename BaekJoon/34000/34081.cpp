// Title : 흰수염과 해적들
// Link  : https://www.acmicpc.net/problem/34081 
// Time  : 232 ms
// Memory: 9144 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, l;
  cin >> n >> l;
  vector<pair<int, int>> arr;
  arr.reserve(n);
  for (int i = 0; i < n; i++) {
    int64_t x, y, c;
    cin >> x >> y >> c;
    int64_t xy = x * x + y * y;
    int64_t r = (int64_t)sqrt((long double)xy);
    while (r * r < xy) ++r;
    int64_t d = l - r;
    if (d >= 0) arr.push_back({d, c});
  }
  sort(arr.begin(), arr.end());

  int64_t maxx = 0, cur = 0;
  priority_queue<int, vector<int>, greater<int>> pq;
  for (auto [d, c] : arr) {
    pq.push(c);
    cur += c;
    if (pq.size() > d + 1) {
      cur -= pq.top();
      pq.pop();
    }
    maxx = max<int64_t>(maxx, cur);
  }
  cout << maxx;

  return 0;
}
