#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1 << 19;

int tree[kMax << 1];
int memo[1000001];

int Query(int l, int r) {
  int res = 0;
  for (l += kMax, r += kMax + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = max<int>(res, tree[l++]);
    if (r & 1) res = max<int>(res, tree[--r]);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int idx = kMax + i;
    while (idx && tree[idx] < x) tree[idx] = x, idx >>= 1;
  }

  int64_t sum = 0;
  for (int i = 0; i < n; i++) {
    int x = tree[kMax + i];
    int l = memo[x], r = i - 1;
    if (l && r - l + 1 > 0 && Query(l, r) < x) {
      sum += r - l + 1;
    }
    memo[x] = i + 1;
  }
  cout << sum;

  return 0;
}
