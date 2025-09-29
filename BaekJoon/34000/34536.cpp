// Title : Hostile Cooperation
// Link  : https://www.acmicpc.net/problem/34536 
// Time  : 72 ms
// Memory: 5288 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 2e5;
constexpr int kShift = 16;
constexpr int kMask = (1 << kShift) - 1;

void Sort(int* arr, int n) {
  int tmp[kMax];
  auto a = arr, b = tmp;
  for (int shift = 0; shift < 32; shift += kShift) {
    int cnt[kMask + 1] = {};
    for (int i = 0; i < n; i++) ++cnt[(a[i] >> shift) & kMask];
    for (int i = 0; i < kMask; i++) cnt[i + 1] += cnt[i];
    int idx = n;
    while (idx--) b[--cnt[(a[idx] >> shift) & kMask]] = a[idx];
    swap(a, b);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, k;
  cin >> n >> k;

  vector<int> arr(n), brr(n), crr(n);
  for (auto& e : arr) cin >> e;
  for (auto& e : brr) cin >> e;
  for (auto& e : crr) cin >> e;

  if (n == 1) {
    cout << abs(k - arr[0] - brr[0] - crr[0]);
    return 0;
  }

  Sort(arr.data(), n), Sort(brr.data(), n);
  auto [minn, maxx] = minmax_element(crr.begin(), crr.end());

  int64_t ans = INT64_MAX;
  int64_t c1 = *minn, c2 = *maxx;
  int64_t pv = k - ((c1 + c2 + 1) >> 1);
  int ai = 0, bi = n - 2;
  while (ai < n) {
    int64_t av = arr[ai++];
    while (bi > 0 && av + brr[bi] >= pv) --bi;
    int64_t b1 = brr[bi], b2 = brr[bi + 1];
    int64_t v1 = max<int64_t>(abs(av + b1 + c1 - k), abs(av + b1 + c2 - k));
    int64_t v2 = max<int64_t>(abs(av + b2 + c1 - k), abs(av + b2 + c2 - k));
    ans = min<int64_t>({ans, v1, v2});
  }
  cout << ans;

  return 0;
}