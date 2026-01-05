// Title : Around the Table
// Link  : https://www.acmicpc.net/problem/35084 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int l, r;
  cin >> l >> r;
  int lr = l + r;

  vector<pair<int, int>> arr;
  arr.push_back({0, l});
  arr.push_back({0, l - 1});
  arr.push_back({lr - l, 0});
  arr.push_back({lr - l + 1, 0});
  for (auto& [a, b] : arr) {
    if (a > b) swap(a, b);
  }
  sort(arr.begin(), arr.end());
  arr.erase(unique(arr.begin(), arr.end()), arr.end());

  cout << lr * arr.size() / 2;

  return 0;
}