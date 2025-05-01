// Title : 하늘에서 정의가 빗발친다!
// Link  : https://www.acmicpc.net/problem/13411 
// Time  : 36 ms
// Memory: 3612 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<tup> arr(n);
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    arr[i] = {a * a + b * b, c * c, i + 1};
  }

  stable_sort(arr.begin(), arr.end(), [](const tup& lhs, const tup& rhs) {
    auto [ld, ls, li] = lhs;
    auto [rd, rs, ri] = rhs;
    return (int64_t)ld * rs < (int64_t)rd * ls;
  });

  for (auto [d, s, i] : arr) cout << i << "\n";

  return 0;
}
