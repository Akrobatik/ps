// Title : Moving Formation
// Link  : https://www.acmicpc.net/problem/34541 
// Time  : 0 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x, y;
  cin >> n >> x >> y;
  int minn = min<int>(x, y);

  vector<tuple<int, int, int>> arr;
  for (int i = n - 1; i >= 1; i--) {
    arr.push_back({2, i, i});
    arr.push_back({1, 0, i});
    arr.push_back({3, i, 0});
  }

  for (int i = 1; i <= x; i++) {
    arr.push_back({3, i + 1, 0});
    arr.push_back({2, i + 1, 1});
    arr.push_back({0, i, 0});
    arr.push_back({1, i, 1});
  }

  for (int i = 1; i <= y; i++) {
    arr.push_back({1, x, i + 1});
    arr.push_back({2, x + 1, i + 1});
    arr.push_back({0, x, i});
    arr.push_back({3, x + 1, i});
  }

  for (int i = 2; i <= n; i++) {
    arr.push_back({1, x, y + i});
    arr.push_back({3, x + i, y});
    arr.push_back({2, x + i, y + i});
  }

  cout << arr.size() << "\n";
  for (auto [a, b, c] : arr) cout << (char)(a + 'A') << " " << b << " " << c << "\n";

  return 0;
}