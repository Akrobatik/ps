// Title : 피보나치
// Link  : https://www.acmicpc.net/problem/9009
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr array<int, 43> kFibs = []() {
  array<int, 43> arr{};
  auto ptr = arr.data();
  int a = 0, b = 1;
  while (a + b <= 1000000000) {
    int tmp = *ptr++ = a + b;
    a = b;
    b = tmp;
  }
  return arr;
}();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> ans;
    for (auto it = kFibs.rbegin(); it != kFibs.rend(); ++it) {
      if (*it <= n) ans.push_back(*it), n -= *it;
    }
    for (auto e : views::reverse(ans)) cout << e << " ";
    cout << "\n";
  }

  return 0;
}
