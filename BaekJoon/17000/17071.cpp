// Title : 숨바꼭질 5
// Link  : https://www.acmicpc.net/problem/17071 
// Time  : 12 ms
// Memory: 6872 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 5e5;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> arr;
  for (int i = 0, x = k; x <= kMax; x += ++i) {
    arr.push_back(x);
  }

  vector<array<int, 2>> dist(kMax + 1, {INT_MAX, INT_MAX});
  queue<int> q;

  auto Push = [&](int x, int d) {
    if (x < 0 || x > kMax || dist[x][d & 1] != INT_MAX) return;
    dist[x][d & 1] = d;
    q.push(x);
  };

  Push(n, 0);
  for (int i = 1; !q.empty(); i++) {
    int nq = q.size();
    while (nq--) {
      int x = q.front();
      q.pop();

      for (int nxt : {x - 1, x + 1, x * 2}) {
        Push(nxt, i);
      }
    }
  }

  int ans = -1, na = arr.size();
  for (int i = 0; i < na; i++) {
    if (dist[arr[i]][i & 1] > i) continue;
    ans = i;
    break;
  }
  cout << ans;

  return 0;
}
