// Title : 음주 코딩
// Link  : https://www.acmicpc.net/problem/5676 
// Time  : 76 ms
// Memory: 4076 KB

#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
  void Init(const vector<int>& arr) {
    int n = arr.size();
    nmax = has_single_bit((uint32_t)n) ? n : (1 << (32 - countl_zero((uint32_t)n)));
    tree.resize(nmax << 1);
    for (int i = 0; i < n; i++) tree[i + nmax] = arr[i];
    for (int i = n; i < nmax; i++) tree[i + nmax] = 1;
    for (int i = nmax - 1; i > 0; i--) tree[i] = tree[i << 1] * tree[(i << 1) + 1];
  }

  void Update(int idx, int value) {
    int node = idx + nmax;
    tree[node] = value;
    while ((node >>= 1)) tree[node] = tree[node << 1] * tree[(node << 1) + 1];
  }

  int Query(int l, int r) {
    int res = 1;
    for (l += nmax, r += nmax + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res *= tree[l++];
      if (r & 1) res *= tree[--r];
    }
    return res;
  }

  int nmax;
  vector<int> tree;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> arr;
  SegmentTree tree;

  int n, k;
  while (cin >> n >> k) {
    arr.resize(n);
    for (auto& e : arr) {
      cin >> e;
      e = (e >= 0) - (e <= 0);
    }
    tree.Init(arr);
    while (k--) {
      char cmd;
      int a, b;
      cin >> cmd >> a >> b;
      if (cmd == 'C') {
        b = (b >= 0) - (b <= 0);
        tree.Update(a - 1, b);
      } else {
        cout << "-0+"[tree.Query(a - 1, b - 1) + 1];
      }
    }
    cout << "\n";
  }

  return 0;
}