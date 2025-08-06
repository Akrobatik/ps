// Title : 수열과 쿼리 18
// Link  : https://www.acmicpc.net/problem/14504 
// Time  : 316 ms
// Memory: 2412 KB

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <immintrin.h>

using namespace std;

int arr[100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  auto Count = [&](int l, int r, int k) {
    int res = 0;

    while (l <= r && (l & 7)) res += (arr[l++] > k);
    __m256i sum = _mm256_setzero_si256();
    const __m256i cmp = _mm256_set1_epi32(k);
    for (; l + 7 <= r; l += 8) {
      __m256i val = _mm256_load_si256((const __m256i*)(arr + l));
      sum = _mm256_add_epi32(sum, _mm256_cmpgt_epi32(val, cmp));
    }
    while (l <= r) res += (arr[l++] > k);

    int cnt[8];
    _mm256_store_si256((__m256i*)cnt, sum);
    for (int i = 0; i < 8; i++) res -= cnt[i];
 
    return res;
  };

  int m;
  cin >> m;
  while (m--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int i, j, k;
      cin >> i >> j >> k;
      cout << Count(i, j, k) << "\n";
    } else {
      int i, k;
      cin >> i >> k;
      arr[i] = k;
    }
  }

  return 0;
}
