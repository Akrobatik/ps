// Title : 해밍 거리와 쿼리
// Link  : https://www.acmicpc.net/problem/14851
// Time  : 504 ms
// Memory: 3192 KB

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <immintrin.h>

using namespace std;

uint8_t b1[8][25000], b2[8][25000];

int Count(int p1, int p2, int len) {
  auto bp1 = b1[p1 % 8], bp2 = b2[p2 % 8];
  p1 -= p1 % 8, p2 -= p2 % 8;

  int cnt = 0, i = 0, pi1 = p1 / 8, pi2 = p2 / 8;
  for (; i + 128 <= len; i += 128, pi1 += 16, pi2 += 16) {
    __m128i v1 = _mm_loadu_si128((const __m128i *)(bp1 + pi1));
    __m128i v2 = _mm_loadu_si128((const __m128i *)(bp2 + pi2));
    __m128i vx = _mm_xor_si128(v1, v2);
    cnt += __builtin_popcountll(_mm_extract_epi64(vx, 0));
    cnt += __builtin_popcountll(_mm_extract_epi64(vx, 1));
  }

  for (; i + 8 <= len; i += 8, pi1++, pi2++) {
    cnt += __builtin_popcount(bp1[pi1] ^ bp2[pi2]);
  }
  for (int j = 0; j < 8 && i < len; i++, j++) {
    cnt += (((bp1[pi1] ^ bp2[pi2]) >> j) & 1);
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s1, s2;
  cin >> s1 >> s2;
  int n1 = s1.size(), n2 = s2.size();
  for (int i = 0; i < n1; i++) {
    if (s1[i] == '0') continue;
    for (int j = 0; j < 8; j++) {
      int p = i - j;
      if (p < 0) continue;
      int pi = p / 8, pb = p % 8;
      b1[j][pi] |= (1ull << pb);
    }
  }
  for (int i = 0; i < n2; i++) {
    if (s2[i] == '0') continue;
    for (int j = 0; j < 8; j++) {
      int p = i - j;
      if (p < 0) continue;
      int pi = p / 8, pb = p % 8;
      b2[j][pi] |= (1ull << pb);
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int p1, p2, len;
    cin >> p1 >> p2 >> len;
    cout << Count(p1, p2, len) << "\n";
  }

  return 0;
}
