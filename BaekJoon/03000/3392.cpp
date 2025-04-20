// Title : 화성 지도
// Link  : https://www.acmicpc.net/problem/3392 
// Time  : 8 ms
// Memory: 2852 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int, int>;

constexpr int kMax = 1 << 15;

pair<int, int> tree[kMax << 1];

void Update(int node, int b, int e, int l, int r, int delta) {
  if (b > r || e < l) return;

  auto& [x, cnt] = tree[node];
  if (l <= b && e <= r) {
    cnt += delta;
  } else {
    int mid = (b + e) >> 1;
    Update(node << 1, b, mid, l, r, delta);
    Update((node << 1) + 1, mid + 1, e, l, r, delta);
  }

  if (cnt > 0) {
    x = e - b + 1;
  } else if (b == e) {
    x = 0;
  } else {
    x = tree[node << 1].first + tree[(node << 1) + 1].first;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<tup> arr(n << 1);
  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    arr[i << 1] = {x1, y1, y2 - 1, 1};
    arr[(i << 1) + 1] = {x2, y1, y2 - 1, -1};
  }

  sort(arr.begin(), arr.end(), [](const tup& lhs, const tup& rhs) {
    return get<0>(lhs) < get<0>(rhs);
  });

  int sum = 0, prv = get<0>(arr[0]);
  for (auto [x, y1, y2, delta] : arr) {
    sum += (x - prv) * tree[1].first;
    prv = x;
    Update(1, 0, kMax - 1, y1, y2, delta);
  }
  cout << sum;

  return 0;
}
