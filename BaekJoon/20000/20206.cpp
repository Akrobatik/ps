// Title : 푸앙이가 길을 건너간 이유
// Link  : https://www.acmicpc.net/problem/20206 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t a, b, c, x1, x2, y1, y2;
  cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;

  auto Calc = [&](int64_t x, int64_t y) {
    return a * x + b * y + c;
  };

  vector<int64_t> arr;
  for (int64_t x : {x1, x2}) {
    for (int64_t y : {y1, y2}) {
      arr.push_back(Calc(x, y));
    }
  }
  sort(arr.begin(), arr.end());

  auto Sign = [&](int64_t v) {
    return v < 0 ? -1 : (v > 0 ? 1 : 0);
  };

  cout << (Sign(arr[0]) * Sign(arr[3]) < 0 ? "Poor" : "Lucky");

  return 0;
}