#include <bits/stdc++.h>

using namespace std;

uint32_t Compress(uint32_t* nums, int n) {
  for (int i = 0; i < n; i++) {
    while (find(nums, nums + n, i) == nums + n) {
      bool skip = true;
      for (int j = 0; j < n; j++) {
        if (nums[j] > i) {
          --nums[j];
          skip = false;
        }
      }
      if (skip) break;
    }
  }

  uint32_t bits = 0;
  for (int i = 0; i < n; i++) bits |= nums[i] << (i * 3);
  return bits;
}

uint32_t Swap(uint32_t bits, int l, int r) {
  uint32_t lb = bits & (0x7 << (l * 3));
  uint32_t rb = bits & (0x7 << (r * 3));
  uint32_t d = (r - l) * 3;
  return bits ^ lb ^ rb ^ (lb << d) ^ (rb >> d);
}

uint32_t Sort(uint32_t bits, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      uint32_t lb = (bits >> (j * 3)) & 0x7;
      uint32_t rb = (bits >> ((j + 1) * 3)) & 0x7;
      if (lb > rb) bits = Swap(bits, j, j + 1);
    }
  }
  return bits;
}

// short memo[1 << 24];
tuple<int, int, int>* edges_bucket[8][8];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  uint32_t nums[8];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> nums[i];
  uint32_t compressed = Compress(nums, n);
  uint32_t ans = Sort(compressed, n);

  int m;
  cin >> m;
  tuple<int, int, int> edges[10];
  auto _edges = edges;
  for (int i = 0; i < m; i++) {
    int l, r, c;
    cin >> l >> r >> c;
    --l, --r;
    if (edges_bucket[l][r]) {
      if (get<0>(*edges_bucket[l][r]) > c) {
        get<0>(*edges_bucket[l][r]) = c;
      }
    } else {
      edges_bucket[l][r] = _edges;
      *_edges++ = {c, l, r};
    }
  }
  m = _edges - edges;

  auto cmp = [](const pair<int, uint32_t>& lhs, const pair<int, uint32_t>& rhs) {
    return lhs.first > rhs.first;
  };

  unordered_map<uint32_t, int> memo;
  priority_queue<pair<int, uint32_t>, vector<pair<int, uint32_t>>, decltype(cmp)> pq;
  pq.push({0, compressed});

  while (!pq.empty()) {
    auto [cost, sbits] = pq.top();
    pq.pop();

    if (ans == sbits) {
      cout << cost;
      return 0;
    }

    if (cost > memo[sbits]) continue;

    for (int i = 0; i < m; i++) {
      auto [c, l, r] = edges[i];
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
