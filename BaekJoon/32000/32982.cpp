// Title : 약물 복용
// Link  : https://www.acmicpc.net/problem/32982 
// Time  : 0 ms
// Memory: 4188 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  vector<pair<int, int>> arr(3);
  cin >> n >> k;
  for (auto& [b, e] : arr) cin >> b >> e;

  if (n >= 2) {
    arr.resize(n * 3);
    for (int i = 3; i < arr.size(); i++) {
      arr[i].first = arr[i - 3].first + 1440;
      arr[i].second = arr[i - 3].second + 1440;
    }
  }

  int t = arr[0].second;
  for (int i = 1; i < arr.size(); i++) {
    if (t + k < arr[i].first) {
      cout << "NO";
      return 0;
    }
    t = min<int>(t + k, arr[i].second);
  }
  cout << "YES";

  return 0;
}
