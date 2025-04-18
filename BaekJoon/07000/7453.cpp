// Title : 합이 0인 네 정수
// Link  : https://www.acmicpc.net/problem/7453 
// Time  : 3036 ms
// Memory: 127088 KB

#include <bits/stdc++.h>

using namespace std;

int ab[16000000], cd[16000000];
int a[4000], b[4000], c[4000], d[4000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }

  auto abe = ab, cde = cd;
  for (int i = 0; i < n; i++) {
    int ax = a[i], cx = c[i];
    for (int j = 0; j < n; j++) {
      *abe++ = ax + b[j];
      *cde++ = cx + d[j];
    }
  }
  sort(ab, abe);
  sort(cd, cde, greater<>());

  int64_t ans = 0;

  auto abi = ab, cdi = cd;
  while (abi != abe && cdi != cde) {
    if (*abi + *cdi == 0) {
      int abx = *abi++, abc = 1;
      while (abi != abe && *abi == abx) ++abi, ++abc;
      int cdx = *cdi++, cdc = 1;
      while (cdi != cde && *cdi == cdx) ++cdi, ++cdc;
      ans += (int64_t)abc * cdc;
      continue;
    }

    if (*abi + *cdi < 0) {
      int cdx = *cdi;
      while (abi != abe && *abi + cdx < 0) ++abi;
    } else {
      int abx = *abi;
      while (cdi != cde && *cdi + abx > 0) ++cdi;
    }
  }
  cout << ans;

  return 0;
}
