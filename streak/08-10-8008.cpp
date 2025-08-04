#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b) {
  while (b) a %= b, swap(a, b);
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  int g = 0;
  for (auto e : arr) g = GCD(g, e);
  for (auto& e : arr) e /= g;

  int limit = arr[0];
  vector<int> axr(limit, INT_MAX);
  for (auto e : arr) {
    int x = e % limit;
    axr[x] = min<int>(axr[x], e);
  }

  vector<int> edges;
  for (int i = 1; i < limit; i++) {
    if (axr[i] == INT_MAX) continue;
    edges.push_back(axr[i]);
  }

  vector<int64_t> dist(limit, INT64_MAX);
  priority_queue<int64_t, vector<int64_t>, greater<int64_t>> pq;

  auto Push = [&](int64_t x) {
    int y = x % limit;
    if (dist[y] <= x) return;
    dist[y] = x;
    pq.push(x);
  };

  Push(0);
  while (!pq.empty()) {
    auto cur = pq.top();
    pq.pop();

    if (dist[cur % limit] != cur) continue;

    for (auto nxt : edges) {
      Push(cur + nxt);
    }
  }

  int m;
  cin >> m;
  while (m--) {
    int64_t x;
    cin >> x;
    if (x % g != 0) {
      cout << "NIE\n";
      continue;
    }
    x /= g;
    cout << (x < dist[x % limit] ? "NIE\n" : "TAK\n");
  }

  return 0;
}
