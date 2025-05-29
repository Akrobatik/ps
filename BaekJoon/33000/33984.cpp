// Title : 피보나치 동전
// Link  : https://www.acmicpc.net/problem/33984 
// Time  : 276 ms
// Memory: 8892 KB

#include <bits/stdc++.h>

using namespace std;

int cnt;
map<int, int, greater<int>> odd, even;

void Push(int x) {
  if (x == 0) return;
  if (x == 1) x = 2;

  if (x == 2) {
    if (auto it = even.find(2); it != even.end()) {
      int y = it->second;
      even.erase(it);
      cnt -= (y >> 1);
      Push(y + 1);
      return;
    }

    if (auto it = odd.find(3); it != odd.end()) {
      int y = it->second;
      odd.erase(it);
      cnt -= ((y - 1) >> 1);
      Push(y + 1);
      return;
    }

    if (auto it = even.find(4); it != even.end()) {
      even[2] = it->second;
      even.erase(it);
      ++cnt;
      return;
    }

    even[2] = 2;
    ++cnt;
    return;
  }

  auto o = &odd;
  auto e = &even;
  if (x & 1) swap(o, e);

  if (auto it = o->lower_bound(x + 1); it != o->end() && it->second >= x - 1) {
    int l = it->first, r = it->second;
    if (r == x - 1) {
      --cnt;
      if (l == r) {
        o->erase(it);
      } else {
        it->second = r - 2;
      }
      Push(x + 1);
      return;
    }

    if (l == x + 1) {
      cnt -= ((r - l + 2) >> 1);
      o->erase(it);
      Push(r + 1);
      return;
    }

    it->second = x - 1;
    cnt -= ((r - x + 1) >> 1);
    Push(r + 1);
    return;
  }

  if (auto it = e->lower_bound(x); it != e->end() && it->second >= x) {
    int l = it->first, r = it->second;
    e->erase(it);

    if (l == r) {
      --cnt;
      Push(x + 1);
      Push(x - 2);
      return;
    }

    if (l == x) {
      cnt -= ((r - l + 2) >> 1);
      Push(l - 2);
      Push(r + 1);
      return;
    }

    if (r == x) {
      --cnt;
      o->insert({l + 1, r - 1});
      Push(l - 2);
      Push(r + 1);
      return;
    }

    cnt -= ((r - x + 2) >> 1);
    o->insert({l + 1, x - 1});
    Push(l - 2);
    Push(r + 1);
    return;
  }

  ++cnt;
  auto lit = e->lower_bound(x);
  if (lit != e->end() && lit->second == x - 2) {
    lit->second = x;
  } else {
    lit = e->insert({x, x}).first;
  }

  if (auto rit = e->find(x + 2); rit != e->end()) {
    lit->second = rit->second;
    e->erase(rit);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    Push(x);
    cout << cnt << " ";
  }

  return 0;
}