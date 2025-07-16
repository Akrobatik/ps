// Title : 소어그래프
// Link  : https://www.acmicpc.net/problem/34061 
// Time  : 36 ms
// Memory: 6124 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  uint64_t n, x, y, t;
  cin >> n >> x >> y >> t;
  --n;
  uint64_t b = 1 << (64 - countl_zero(t));
  uint64_t m = b - 1;

  uint64_t nm = n ^ (n & m);
  uint64_t xm = x ^ (x & m);
  uint64_t ym = y ^ (y & m);

  if (xm > ym) {
    cout << "-1";
    return 0;
  }

  uint64_t cyc = (ym - xm) / b;

  uint64_t limit;
  vector<int> dist;
  queue<uint64_t> q;

  auto GetDist = [&](uint64_t x) {
    return x <= limit ? dist[x] : -1;
  };

  auto Push = [&](uint64_t x, int d) {
    if (x > limit || dist[x] != -1) return;
    dist[x] = d;
    q.push(x);
  };

  if (cyc == 0) {
    limit = (nm > ym ? b : (m & n));
    dist.assign(limit + 1, -1);

    Push(x & m, 0);
    for (int i = 1; !q.empty(); i++) {
      int nq = q.size();
      while (nq--) {
        uint64_t cur = q.front();
        q.pop();

        for (uint64_t nxt : {cur ^ t, (cur ^ t) + 1}) {
          Push(nxt, i);
        }
      }
    }

    cout << GetDist(y & m);
    return 0;
  }

  limit = b;
  dist.assign(limit + 1, -1);

  Push(x & m, 0);
  for (int i = 1; !q.empty(); i++) {
    int nq = q.size();
    while (nq--) {
      uint64_t cur = q.front();
      q.pop();

      for (uint64_t nxt : {cur ^ t, (cur ^ t) + 1}) {
        Push(nxt, i);
      }
    }
  }

  int x0 = GetDist(b);
  if (x0 == -1) {
    cout << "-1";
    return 0;
  }

  dist.assign(limit + 1, -1);

  Push(0, 0);
  for (int i = 1; !q.empty(); i++) {
    int nq = q.size();
    while (nq--) {
      uint64_t cur = q.front();
      q.pop();

      for (uint64_t nxt : {cur ^ t, (cur ^ t) + 1}) {
        Push(nxt, i);
      }
    }
  }

  int cd = GetDist(b);
  if (cd == -1) {
    cout << "-1";
    return 0;
  }

  limit = (nm > ym ? b : (m & n));
  dist.assign(limit + 1, -1);

  Push(0, 0);
  for (int i = 1; !q.empty(); i++) {
    int nq = q.size();
    while (nq--) {
      uint64_t cur = q.front();
      q.pop();

      for (uint64_t nxt : {cur ^ t, (cur ^ t) + 1}) {
        Push(nxt, i);
      }
    }
  }

  int y0 = GetDist(y & m);
  if (y0 == -1) {
    cout << "-1";
    return 0;
  }

  cout << (cyc - 1) * cd + x0 + y0;

  return 0;
}
