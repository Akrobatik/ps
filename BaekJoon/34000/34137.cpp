// Title : 빛의 길
// Link  : https://www.acmicpc.net/problem/34137 
// Time  : 356 ms
// Memory: 13644 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int, int>;

constexpr int kMax = 1 << 18;

int64_t tree[kMax << 1];
int lazy[kMax << 1];

void Push(int node, int b, int e) {
  if (!lazy[node]) return;
  tree[node] = (int64_t)lazy[node] * (e - b + 1);
  if (b != e) {
    lazy[node << 1] = lazy[node];
    lazy[(node << 1) + 1] = lazy[node];
  }
  lazy[node] = 0;
}

void Update(int node, int b, int e, int l, int r, int val) {
  bool fit = (l <= b && e <= r);
  if (fit) lazy[node] = val;
  Push(node, b, e);
  if (l > e || b > r || fit) return;
  int mid = (b + e) >> 1;
  Update(node << 1, b, mid, l, r, val);
  Update((node << 1) + 1, mid + 1, e, l, r, val);
  tree[node] = tree[node << 1] + tree[(node << 1) + 1];
}

int64_t Query(int node, int b, int e, int l, int r) {
  Push(node, b, e);
  if (l > e || b > r) return 0;
  if (l <= b && e <= r) return tree[node];
  int mid = (b + e) >> 1;
  return Query(node << 1, b, mid, l, r) + Query((node << 1) + 1, mid + 1, e, l, r);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, t, k;
  cin >> n >> m >> t >> k;

  vector<int> arr(m + 1);
  for (int i = 1; i <= m; i++) cin >> arr[i];

  vector<tup> axr(k);
  for (auto& [r, s, e, c] : axr) cin >> r >> s >> e >> c;
  sort(axr.begin(), axr.end(), greater<tup>());

  vector<int64_t> cnts(t + 1);
  for (auto [r, s, e, c] : axr) {
    int64_t h = n - r + 1;
    cnts[c] += h * (e - s + 1) - Query(1, 0, kMax - 1, s, e);
    Update(1, 0, kMax - 1, s, e, h);
  }

  for (int i = 1; i <= m; i++) {
    cnts[arr[i]] += n - Query(1, 0, kMax - 1, i, i);
  }

  for (int i = 1; i <= t; i++) cout << cnts[i] << " ";

  return 0;
}
