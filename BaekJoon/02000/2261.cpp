// Title : 가장 가까운 두 점
// Link  : https://www.acmicpc.net/problem/2261 
// Time  : 44 ms
// Memory: 4104 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kThreshold = 4;

int GetDistance(const pair<int, int>& a, const pair<int, int>& b) {
  int dy = a.first - b.first;
  int dx = a.second - b.second;
  return dy * dy + dx * dx;
}

int GetMin(span<pair<int, int>> coords) {
  if (coords.size() <= kThreshold) {
    sort(coords.begin(), coords.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
      return lhs.first < rhs.first;
    });

    int minn = INT_MAX;
    for (int i = 0; i < coords.size(); i++) {
      for (int j = i + 1; j < coords.size(); j++) {
        minn = min<int>(minn, GetDistance(coords[i], coords[j]));
      }
    }
    return minn;
  }

  int mid = coords.size() >> 1;
  int mx = coords[mid].second;
  auto l = coords.subspan(0, mid);
  auto r = coords.subspan(mid);
  int minn = min<int>(GetMin(l), GetMin(r));

  vector<pair<int, int>> tmp(coords.size());
  merge(l.begin(), l.end(), r.begin(), r.end(), tmp.begin(), [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
    return lhs.first < rhs.first;
  });
  copy(tmp.begin(), tmp.end(), coords.begin());

  tmp.clear();
  for (auto [y, x] : coords) {
    int dx = x - mx;
    if (dx * dx < minn) tmp.push_back({y, x});
  }

  for (int i = 0; i < tmp.size(); i++) {
    auto [iy, ix] = tmp[i];
    for (int j = i + 1; j < tmp.size(); j++) {
      auto [jy, jx] = tmp[j];
      int dy = iy - jy, dx = ix - jx;
      if (dy * dy >= minn) break;
      minn = min<int>(minn, dy * dy + dx * dx);
    }
  }
  return minn;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> coords(n);
  for (auto& [y, x] : coords) cin >> x >> y;
  sort(coords.begin(), coords.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
    return lhs.second < rhs.second;
  });
  cout << GetMin(coords);

  return 0;
}
