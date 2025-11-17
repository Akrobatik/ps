// Title : 아 마이마이 하고 싶다
// Link  : https://www.acmicpc.net/problem/34692 
// Time  : 0 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, m, k;
  cin >> n >> m >> k;

  priority_queue<int64_t, vector<int64_t>, greater<int64_t>> pq;
  while (m--) pq.push(0);

  while (n--) {
    int64_t x;
    cin >> x;

    x += pq.top();
    pq.pop();

    pq.push(x);
  }

  int64_t x = pq.top();
  cout << (x <= k ? "WAIT" : "GO");

  return 0;
}