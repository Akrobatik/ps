// Title : 작은 수는 싫어!
// Link  : https://www.acmicpc.net/problem/34405 
// Time  : 420 ms
// Memory: 29760 KB

#include <bits/stdc++.h>

using namespace std;

template <typename V, typename OP>
  requires requires(V a, V b) {
    { OP{}(a, b) } -> convertible_to<V>;
  }
struct SegTree {
  void Init(int n, const V& ival) {
    nmax = bit_ceil((uint32_t)n);
    iv = ival;
    tree.assign(nmax << 1, iv);
  }

  void Set(int idx, const V& val) {
    tree[idx + nmax] = val;
  }

  void Build() {
    for (int i = nmax - 1; i > 0; i--) {
      tree[i] = OP{}(tree[i << 1], tree[i << 1 | 1]);
    }
  }

  void Update(int idx, const V& val) {
    int node = idx + nmax;
    tree[node] = val;
    while (node >>= 1) {
      tree[node] = OP{}(tree[node << 1], tree[node << 1 | 1]);
    }
  }

  V Query(int idx) const {
    return tree[idx + nmax];
  }

  V Query(int l, int r) const {
    V lv = iv, rv = iv;
    for (l += nmax, r += nmax + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) lv = OP{}(lv, tree[l++]);
      if (r & 1) rv = OP{}(tree[--r], rv);
    }
    return OP{}(lv, rv);
  }

 private:
  int nmax;
  V iv;
  vector<V> tree;
};

using Node = int;

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    return max<int>(a, b);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int64_t> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    arr[i] = arr[i - 1] + x;
  }

  auto axr = arr;
  sort(axr.begin(), axr.end());
  axr.erase(unique(axr.begin(), axr.end()), axr.end());

  for (auto& e : arr) {
    int64_t l = lower_bound(axr.begin(), axr.end(), e) - axr.begin();
    int64_t r = upper_bound(axr.begin(), axr.end(), e - k) - axr.begin();
    e = l << 32 | r;
  }

  int na = axr.size();
  SegTree<Node, FOp> seg;
  seg.Init(na, -1);
  seg.Update(arr[0] >> 32, 0);

  vector<int> memo(n + 1);
  for (int i = 1; i <= n; i++) {
    int64_t lr = arr[i];
    int64_t l = lr >> 32, r = lr ^ (l << 32);
    int maxx = max<int>(seg.Query(0, r - 1) + 1, seg.Query(l));
    seg.Update(l, maxx);
  }
  cout << seg.Query(0, na - 1);

  return 0;
}