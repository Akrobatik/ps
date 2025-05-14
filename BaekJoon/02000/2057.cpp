// Title : 팩토리얼 분해
// Link  : https://www.acmicpc.net/problem/2057 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  cin >> n;
  if (n == 0) {
    cout << "NO";
    return 0;
  }

  int64_t x = 1;
  vector<int64_t> arr{1};
  for (int i = 1; x <= n / i; i++) {
    x *= i;
    arr.push_back(x);
  }

  for (auto e : views::reverse(arr)) {
    if (n >= e) n -= e;
  }

  cout << (n == 0 ? "YES" : "NO");

  return 0;
}
