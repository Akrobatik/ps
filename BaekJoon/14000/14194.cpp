// Title : Grades
// Link  : https://www.acmicpc.net/problem/14194
// Time  : 24 ms
// Memory: 2532 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int64_t> arr(n);
    int64_t y = 0;
    for (auto& e : arr) cin >> e, y += e;
    sort(arr.begin(), arr.end());
    int64_t x = (arr.front() + arr.back()) * n;
    y <<= 1;
    cout << (abs(x - y) <= n * 2 ? "Yes\n" : "No\n");
  }

  return 0;
}
