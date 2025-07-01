// Title : 수열 재배열
// Link  : https://www.acmicpc.net/problem/27739 
// Time  : 36 ms
// Memory: 2160 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> arr(n + 2), fwd(n + 2), bwd(n + 2), tmp(k);
  for (int i = 1; i <= n; i++) cin >> arr[i];
  arr[n + 1] = INT_MAX;

  int l = 1, r = 1;
  while (l <= n) {
    r = max<int>(r, l);
    while (r + 1 <= n && arr[r] < arr[r + 1]) ++r;
    fwd[l++] = r - l + 1;
  }
  l = n, r = n;
  while (r >= 1) {
    l = min<int>(l, r);
    while (l - 1 >= 1 && arr[l - 1] < arr[l]) --l;
    bwd[r--] = r - l + 1;
  }

  int maxx = 0;
  for (int i = 1; i + k - 1 <= n; i++) {
    copy(arr.begin() + i, arr.begin() + i + k, tmp.begin());
    sort(tmp.begin(), tmp.end());
    if (arr[i - 1] < tmp.front() && tmp.back() < arr[i + k]) {
      maxx = max<int>(maxx, bwd[i - 1] + fwd[i + k] + k);
    } else {
      int fmax = bwd[i - 1] + (tmp.end() - upper_bound(tmp.begin(), tmp.end(), arr[i - 1]));
      int bmax = fwd[i + k] + (tmp.rend() - upper_bound(tmp.rbegin(), tmp.rend(), arr[i + k], greater<int>()));
      maxx = max<int>({maxx, fmax, bmax});
    }
  }
  cout << maxx;

  return 0;
}
