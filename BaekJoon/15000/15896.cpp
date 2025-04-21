// Title : &+ +&
// Link  : https://www.acmicpc.net/problem/15896 
// Time  : 456 ms
// Memory: 13748 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1999;

vector<int> tmp;

int Sort(vector<int>& arr, int bit) {
  tmp.resize(arr.size());

  int cnt[2] = {};
  for (auto e : arr) ++cnt[(e & bit) == bit];
  int res = cnt[1];
  cnt[1] += cnt[0];

  for (auto e : views::reverse(arr)) {
    tmp[--cnt[(e & bit) == bit]] = e;
  }
  copy(tmp.begin(), tmp.end(), arr.begin());
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n), brr(n);
  for (auto& e : arr) cin >> e;
  for (auto& e : brr) cin >> e;

  int ans1 = 0, ans2 = 0;
  for (int i = 0; i < 29; i++) {
    int bit = 1 << i;
    int acnt = Sort(arr, bit), bcnt = Sort(brr, bit);
    ans1 += ((int64_t)acnt * bcnt % kMod) * bit % kMod;

    bool ok = true;
    for (auto aidx : {0, n - 1, n - acnt, n - acnt - 1}) {
      if (aidx == -1 || aidx == n) continue;
      for (auto bidx : {0, n - 1, n - bcnt, n - bcnt - 1}) {
        if (bidx == -1 || bidx == n) continue;
        if (!((arr[aidx] + brr[bidx]) & bit)) ok = false;
      }
    }
    if (ok) ans2 |= bit;
  }
  if (arr.front() + brr.front() >= (1 << 29)) ans2 |= (1 << 29);

  cout << ans1 % kMod << " " << ans2;

  return 0;
}
