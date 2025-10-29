// Title : 화학실험
// Link  : https://www.acmicpc.net/problem/1954 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    pq.push({a + b, a});
  }

  int m;
  cin >> m;

  if (n > m) {
    cout << "0";
    return 0;
  }
  m -= n;

  while (m--) {
    auto [s, a] = pq.top();
    pq.pop();

    pq.push({s + a, a});
  }

  bool ok = true;
  int x = pq.top().first;
  for (int i = 0; ok && i < n; i++) {
    auto [s, a] = pq.top();
    pq.pop();
    ok = (s == x);
  }
  cout << (ok ? x : 0);

  return 0;
}