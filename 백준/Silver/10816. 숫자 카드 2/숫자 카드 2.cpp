#include <bits/stdc++.h>

using namespace std;

int nums[500000];
int ans[500000];
pair<int, int*> queries[500000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> nums[i];
  sort(nums, nums + n);

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int v;
    cin >> v;
    queries[i] = {v, ans + i};
  }
  sort(queries, queries + m, [](const pair<int, int*>& lhs, const pair<int, int*>& rhs) {
    return lhs.first < rhs.first;
  });

  auto it = nums;
  for (int i = 0; i < m; i++) {
    auto b = lower_bound(it, nums + n, queries[i].first);
    auto e = lower_bound(b, nums + n, queries[i].first + 1);
    *queries[i].second = e - b;
    while (i + 1 != m && queries[i].first == queries[i + 1].first) {
      *queries[++i].second = e - b;
    }
    it = e;
  }

  for (int i = 0; i < m; i++) cout << ans[i] << " ";

  return 0;
}
