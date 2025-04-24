// Title : 아이템
// Link  : https://www.acmicpc.net/problem/28122 
// Time  : 212 ms
// Memory: 5148 KB

#include <bits/stdc++.h>

using namespace std;

int64_t tmp[200000];

int Traverse(span<int64_t> arr, int rem, int add) {
  if (arr.empty()) return 0;
  if (rem == 0) return arr.size();

  int cnt[2] = {};
  for (auto e : arr) ++cnt[e & 1];

  auto brr = arr.subspan(0, cnt[0]);
  auto crr = arr.subspan(cnt[0]);

  cnt[1] += cnt[0];
  for (auto e : views::reverse(arr)) {
    tmp[--cnt[e & 1]] = e;
  }

  int n = arr.size();
  for (int i = 0; i < n; i++) {
    arr[i] = tmp[i] >> 1;
  }

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
