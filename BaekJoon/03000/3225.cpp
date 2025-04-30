// Title : mapa
// Link  : https://www.acmicpc.net/problem/3225 
// Time  : 48 ms
// Memory: 4104 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kThreshold = 4;

int GetDistance(const pair<int, int>& a, const pair<int, int>& b) {
  auto [ay, ax] = a;
  auto [by, bx] = b;
  return max<int>(abs(ay - by), abs(ax - bx));
}

int GetMin(span<pair<int, int>> coords) {
  if (coords.size() <= kThreshold) {
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
    if (abs(x - mx) < minn) tmp.push_back({y, x});
  }

  sort(tmp.begin(), tmp.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
    return lhs.first < rhs.first;
  });

  for (int i = 0; i < tmp.size(); i++) {
    for (int j = i + 1; j < tmp.size() && abs(tmp[i].first - tmp[j].first) < minn; j++) {
      minn = min<int>(minn, GetDistance(tmp[i], tmp[j]));
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
  for (auto& [y, x] : coords) cin >> x >> y, y *= 3;

  sort(coords.begin(), coords.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
    return lhs.second < rhs.second;
  });

  cout << setprecision(2) << fixed << ((double)GetMin(coords) / 3.0);

  return 0;
}
