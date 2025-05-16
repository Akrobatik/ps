// Title : 나의 FIFA 팀 가치는?
// Link  : https://www.acmicpc.net/problem/29160 
// Time  : 172 ms
// Memory: 8332 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<priority_queue<int>> pq(11);

  int n, k;
  cin >> n >> k;
  while (n--) {
    int p, w;
    cin >> p >> w;
    pq[p - 1].push(w);
  }

  auto Get = [&](int i) {
    if (pq[i].empty()) return 0;
    int w = pq[i].top();
    pq[i].pop();
    if (w != 1) pq[i].push(w - 1);
    return w;
  };

  int ans = 0;
  ++k;
  while (k--) {
    int sum = 0;
    for (int i = 0; i < 11; i++) sum += Get(i);
    ans = sum;
  }
  cout << ans;

  return 0;
}
