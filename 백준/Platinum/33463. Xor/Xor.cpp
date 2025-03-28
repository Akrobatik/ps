#include <bits/stdc++.h>

using namespace std;

int64_t Count(span<int> brr, span<int> crr, int bit) {
  int64_t cnt = 0, idx = 0, nc = crr.size();
  auto rit = crr.rbegin();
  for (auto b : brr) {
    while (idx < nc && b + rit[idx] >= bit) ++idx;
    cnt += idx;
  }
  return cnt;
}

int64_t Excl(span<int> arr, int bit) {
  int64_t cnt = 0;
  bit >>= 1;
  for (auto e : arr) {
    if (e & bit) ++cnt;
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n), memo(n);
  for (auto& e : arr) cin >> e;

  int ans = 0;
  for (int bit = 1; bit < (1 << 30); bit <<= 1) {
    int idx = 0;
    while (idx < n && (arr[idx] & bit)) ++idx;
    for (int i = idx + 1; i < n; i++) {
      if (arr[i] & bit) swap(arr[idx++], arr[i]);
    }
    copy(arr.begin(), arr.end(), memo.begin());
    int mask = bit - 1;
    for (auto& e : memo) e &= mask;
    auto brr = span<int>(memo.begin(), memo.begin() + idx);
    auto crr = span<int>(memo.begin() + idx, memo.end());
    sort(brr.begin(), brr.end());
    sort(crr.begin(), crr.end());

    int64_t cnt = ((Count(brr, brr, bit) + Count(crr, crr, bit) + Excl(memo, bit)) >> 1)  //
                  + (int64_t)brr.size() * crr.size() - Count(brr, crr, bit);
    if (cnt & 1) ans |= bit;
  }
  cout << ans;

  return 0;
}
