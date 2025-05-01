// Title : 하늘에서 정의가 빗발친다!
// Link  : https://www.acmicpc.net/problem/13411 
// Time  : 36 ms
// Memory: 3080 KB

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

  sort(arr.begin(), arr.end(), [](const tup& lhs, const tup& rhs) {
    auto [ld, ls, li] = lhs;
    auto [rd, rs, ri] = rhs;
    int64_t l = (int64_t)ld * rs, r = (int64_t)rd * ls;
    return l < r || (l == r && li < ri);
  });

  for (auto [d, s, i] : arr) cout << i << "\n";

  return 0;
}
