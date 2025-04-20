// Title : 화성 지도
// Link  : https://www.acmicpc.net/problem/3392 
// Time  : 272 ms
// Memory: 2340 KB

#include <bits/stdc++.h>

using namespace std;

int memo[30000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<tuple<int, int, int, int>> arr(n);
  for (auto& [x1, x2, y1, y2] : arr) cin >> x1 >> y1 >> x2 >> y2;
  sort(arr.begin(), arr.end());

  int sum = 0;
  for (auto [x1, x2, y1, y2] : arr) {
    for (int i = y1; i < y2; i++) {
      sum += max<int>(x2, memo[i]) - max<int>(x1, memo[i]);
      memo[i] = max<int>(memo[i], x2);
    }
  }
  cout << sum;

  return 0;
}
