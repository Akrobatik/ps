// Title : 굉장한 학생
// Link  : https://www.acmicpc.net/problem/2336 
// Time  : 172 ms
// Memory: 11980 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

constexpr int kMax = 1 << 19;

int tree[kMax << 1];

int Query(int l, int r) {
  int res = INT_MAX;
  for (l += kMax, r += kMax + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = min<int>(res, tree[l++]);
    if (r & 1) res = min<int>(res, tree[--r]);
  }
  return res;
}

void Update(int idx, int x) {
  int node = idx + kMax;
  while (node && tree[node] > x) tree[node] = x, node >>= 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  fill_n(tree, kMax << 1, INT_MAX);

  int n;
  cin >> n;
  vector<tup> arr(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    get<0>(arr[x - 1]) = i;
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    get<1>(arr[x - 1]) = i;
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    get<2>(arr[x - 1]) = i;
  }

  sort(arr.begin(), arr.end(), [](const tup& lhs, const tup& rhs) {
    return get<0>(lhs) < get<0>(rhs);
  });

  int sum = 0;
  for (auto [a, b, c] : arr) {
    if (Query(0, b - 1) > c) ++sum;
    Update(b, c);
  }
  cout << sum;

  return 0;
}
