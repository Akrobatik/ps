// Title : 이진 검색 트리 복원하기
// Link  : https://www.acmicpc.net/problem/32028 
// Time  : 104 ms
// Memory: 25904 KB

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> layers[200002];
vector<pair<int, int>> ans;

void Traverse(int idx, int h, int mid, int lo, int hi) {
  auto& layer = layers[h + 1];
  auto lit = lower_bound(layer.rbegin(), layer.rend(), mid - 1, [](const pair<int, int>& lhs, int rhs) {
    return lhs.first > rhs;
  });
  if (lit != layer.rend() && lit->first >= lo) {
    ans[idx].first = lit->second + 1;
    Traverse(lit->second, h + 1, lit->first, lo, mid - 1);
  }

  auto rit = lower_bound(layer.begin(), layer.end(), mid + 1, [](const pair<int, int>& lhs, int rhs) {
    return lhs.first < rhs;
  });
  if (rit != layer.end() && rit->first <= hi) {
    ans[idx].second = rit->second + 1;
    Traverse(rit->second, h + 1, rit->first, mid + 1, hi);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int mh = 0;
  for (int i = 0; i < n; i++) {
    int a, h;
    cin >> a >> h;
    mh = max<int>(mh, h);
    layers[h].push_back({a, i});
  }
  for (int i = 1; i <= mh; i++) {
    sort(layers[i].begin(), layers[i].end());
  }
  ans.assign(n, {-1, -1});

  if (layers[1].size() != 1) {
    cout << "-1";
    return 0;
  }

  auto [rv, ri] = layers[1][0];
  Traverse(ri, 1, rv, -2e9, 2e9);

  int cnt = 1;
  for (auto [l, r] : ans) {
    cnt += (l != -1) + (r != -1);
  }

  if (cnt != n) {
    cout << "-1";
    return 0;
  }

  for (auto [l, r] : ans) {
    cout << l << " " << r << "\n";
  }

  return 0;
}
