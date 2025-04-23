// Title : 연봉 998244353원 주세요
// Link  : https://www.acmicpc.net/problem/32765 
// Time  : 28 ms
// Memory: 2916 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int q;
  vector<int64_t> arr{0};
  cin >> arr[0] >> q;

  int64_t x, y;
  do {
    x = arr.size(), y = (arr.back() / x + 1) * x;
    arr.push_back(y);
  } while (x * x != y);

  while (q--) {
    cin >> y;
    if (y < arr.size()) {
      cout << arr[y] << "\n";
    } else {
      cout << x * y << "\n";
    }
  }

  return 0;
}
