// Title : 파일 합치기 3
// Link  : https://www.acmicpc.net/problem/13975 
// Time  : 644 ms
// Memory: 14436 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  priority_queue<int64_t, vector<int64_t>, greater<>> pq;

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    while (n--) {
      int x;
      cin >> x;
      pq.push(x);
    }

    int64_t ans = 0;
    while (pq.size() != 1) {
      int64_t a = pq.top();
      pq.pop();
      int64_t b = pq.top();
      pq.pop();
      ans += a + b;
      pq.push(a + b);
    }
    pq.pop();
    cout << ans << "\n";
  }

  return 0;
}
