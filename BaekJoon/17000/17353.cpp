// Title : 하늘에서 떨어지는 1, 2, ..., R-L+1개의 별
// Link  : https://www.acmicpc.net/problem/17353 
// Time  : 128 ms
// Memory: 10628 KB

#include <bits/stdc++.h>

using namespace std;

struct LazySegmentTree {
  void Init(int n) {
    nmax = has_single_bit((uint32_t)n) ? n : (1 << (32 - countl_zero((uint32_t)n)));
    tree.clear(), tree.resize(nmax << 1);
    lazy.clear(), lazy.resize(nmax << 1);
  }

  void Update(int l, int r, int64_t delta) {
    Update(1, 0, nmax - 1, l, r, delta);
  }

  int64_t Query(int l, int r) {
    return Query(1, 0, nmax - 1, l, r);
  }

  int nmax;
  vector<int64_t> tree, lazy;

 private:
  void Push(int node, int b, int e) {
    if (!lazy[node]) return;
    tree[node] += lazy[node] * (e - b + 1);
    if (b != e) {
      lazy[node << 1] += lazy[node];
      lazy[(node << 1) + 1] += lazy[node];
    }
    lazy[node] = 0;
  }

  void Update(int node, int b, int e, int l, int r, int delta) {
    bool fit = (l <= b && e <= r);
    if (fit) lazy[node] += delta;
    Push(node, b, e);
    if (l > e || b > r || fit) return;
    int mid = (b + e) >> 1;
    Update(node << 1, b, mid, l, r, delta);
    Update((node << 1) + 1, mid + 1, e, l, r, delta);
    tree[node] = tree[node << 1] + tree[(node << 1) + 1];
  }

  int64_t Query(int node, int b, int e, int l, int r) {
    Push(node, b, e);
    if (l > e || b > r) return 0;
    if (l <= b && e <= r) return tree[node];
    int mid = (b + e) >> 1;
    return Query(node << 1, b, mid, l, r) + Query((node << 1) + 1, mid + 1, e, l, r);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  LazySegmentTree plus, minus;

  int n;
  cin >> n;
  plus.Init(n), minus.Init(n);

  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  int q;
  cin >> q;
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int l, r;
      cin >> l >> r;
      plus.Update(l - 1, r - 1, 1);
      minus.Update(l - 1, r - 1, l - 1);
    } else {
      int x;
      cin >> x;
      cout << plus.Query(x - 1, x - 1) * x - minus.Query(x - 1, x - 1) + arr[x - 1] << "\n";
    }
  }

  return 0;
}
