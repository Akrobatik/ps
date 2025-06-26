// Title : 가장 가까운 분수
// Link  : https://www.acmicpc.net/problem/2137 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kLimit = 32767;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t p, q;
  cin >> p >> q;

  int64_t lp = 0, lq = 1;
  int64_t rp = 1, rq = 0;

  for (;;) {
    int64_t mp = lp + rp;
    int64_t mq = lq + rq;
    if (mp == p && mq == q) break;

    if (p * mq < q * mp) {
      rp = mp;
      rq = mq;
    } else {
      lp = mp;
      lq = mq;
    }
  }

  int64_t lk = (kLimit - lq) / q;
  int64_t la = lp + lk * p;
  int64_t lb = lq + lk * q;

  int64_t rk = (kLimit - rq) / q;
  int64_t ra = rp + rk * p;
  int64_t rb = rq + rk * q;

  int64_t ln = abs(p * lb - q * la);
  int64_t ld = q * lb;

  int64_t rn = abs(p * rb - q * ra);
  int64_t rd = q * rb;

  int64_t lv = ln * rd;
  int64_t rv = rn * ld;

  if (lv < rv || (lv == rv && la * rb < ra * lb)) {
    cout << la << " " << lb;
  } else {
    cout << ra << " " << rb;
  }

  return 0;
}
