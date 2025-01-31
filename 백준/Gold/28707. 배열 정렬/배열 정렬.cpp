#include <bits/stdc++.h>

using namespace std;

uint32_t Swap(uint32_t bits, int l, int r) {
  uint32_t lb = bits & (0xF << (l << 2));
  uint32_t rb = bits & (0xF << (r << 2));
  uint32_t d = (r - l) << 2;
  return bits ^ lb ^ rb ^ (lb << d) ^ (rb >> d);
}

uint32_t Sort(uint32_t bits) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 7 - i; j++) {
      uint32_t lb = (bits >> (j << 2)) & 0xF;
      uint32_t rb = (bits >> ((j + 1) << 2)) & 0xF;
      if (lb && rb && lb > rb) bits = Swap(bits, j, j + 1);
    }
  }
  return bits;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  uint32_t seq = 0;
  int n;
  cin >> n;
  int v;
  for (int i = 0; i < n; i++) cin >> v, seq |= v << (i << 2);
  uint32_t ans = Sort(seq);

  int m;
  cin >> m;
  vector<tuple<int, int, int>> edges(m);
  for (int i = 0; i < m; i++) {
    int l, r, c;
    cin >> l >> r >> c;
    edges[i] = {c, l - 1, r - 1};
  }

  unordered_map<uint32_t, int> memo;
  priority_queue<pair<int, uint32_t>, vector<pair<int, uint32_t>>, greater<>> pq;
  pq.push({0, seq});

  while (!pq.empty()) {
    auto [cost, sbits] = pq.top();
    pq.pop();

    if (ans == sbits) {
      cout << cost;
      return 0;
    }

    if (cost > memo[sbits]) continue;

    for (auto [c, l, r] : edges) {
      uint32_t tmp = Swap(sbits, l, r);
      if (auto it = memo.find(tmp); it == memo.end() || cost + c < it->second) {
        memo[tmp] = cost + c;
        pq.push({cost + c, tmp});
      }
    }
  }
  cout << -1;
  return 0;
}
