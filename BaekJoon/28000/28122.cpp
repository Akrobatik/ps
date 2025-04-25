// Title : 아이템
// Link  : https://www.acmicpc.net/problem/28122 
// Time  : 172 ms
// Memory: 3584 KB

#include <bits/stdc++.h>

using namespace std;

int Traverse(span<int64_t> arr, int rem, int add) {
  if (arr.empty()) return 0;
  if (rem == 0) return arr.size();

  auto ab = arr.data(), ae = ab + arr.size();
  auto am = partition(ab, ae, [](int64_t x) {
    return x & 1;
  });
  for (auto& e : arr) e >>= 1;

  auto brr = span<int64_t>(ab, am);
  auto crr = span<int64_t>(am, ae);
  int maxx = max<int>(Traverse(brr, rem - 1, 1), Traverse(crr, rem - 1, 1)) + add;
  return min<int>(maxx, arr.size());
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int64_t> arr(n);
  for (auto& e : arr) cin >> e;
  auto [minn, maxx] = minmax_element(arr.begin(), arr.end());
  int64_t delta = *maxx - *minn;
  cout << Traverse(arr, 64 - countl_zero((uint64_t)delta), 0);

  return 0;
}
