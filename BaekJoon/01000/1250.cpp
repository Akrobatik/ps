// Title : 색칠된 공들
// Link  : https://www.acmicpc.net/problem/1250
// Time  : 1420 ms
// Memory: 119208 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 10000001;

int memo[kMax + 1];
int lens[kMax];
int heap[kMax];
auto hit = heap;

bool Compare(int l, int r) {
  return lens[l] != lens[r] ? lens[l] < lens[r] : l > r;
}

void Push(int idx) {
  *hit++ = idx;
  push_heap(heap, hit, Compare);
}

int Pop() {
  int top = heap[0];
  pop_heap(heap, hit, Compare);
  --hit;
  return top;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  char last;
  cin >> n >> k >> last;
  int len = 1, idx;
  for (int i = 2; i <= n; i++) {
    char c;
    cin >> c;
    if (last != c) {
      idx = i - len;
      memo[i - 1] = idx << 7;
      memo[idx] = ((i - 1) << 7) | last;
      lens[idx] = len;
      Push(idx);
      last = c;
      len = 1;
    } else {
      ++len;
    }
  }
  idx = n - len + 1;
  memo[n] = idx << 7;
  memo[idx] = (n << 7) | last;
  lens[idx] = len;
  Push(idx);

  int ans = 0;
  while (hit != heap) {
    int top = Pop();
    if (!(memo[top] & 0x7F)) continue;
    ++ans;
    int ridx = memo[top] >> 7;
    int l = min<int>(top, ridx);
    int r = memo[l] >> 7;
    if (l <= k && k <= r) break;

    int lr = l - 1;
    int ll = memo[lr] >> 7;
    int lm, ls;
    char lc;
    if ((memo[ll] >> 7) < ll) {
      lm = ll;
      ls = lens[lm];
      lc = memo[lm] & 0x7F;
      ll = memo[lm] >> 7;
    } else {
      lm = 0;
      ls = lens[ll];
      lc = memo[ll] & 0x7F;
    }

    int rl = r + 1;
    int rr = memo[rl] >> 7;
    int rm, rs;
    char rc;
    if (rr != kMax && rl != (memo[rr] >> 7)) {
      rm = memo[rr] >> 7;
      rs = lens[rm];
      rc = memo[rm] & 0x7F;
    } else {
      rm = 0;
      rs = lens[rl];
      rc = memo[rl] & 0x7F;
    }

    if (ll && lr && rl && rr && lc && lc == rc) {
      memo[lm ? lm : ll] ^= lc;
      memo[rm ? rm : rl] ^= rc;
      memo[ll] = rr << 7;
      memo[rr] = top << 7;
      memo[top] = (ll << 7) | lc;
      lens[top] = ls + rs;
      Push(top);
    } else {
      memo[top] = memo[l] = 0;
      if (ll) memo[ll] = (r << 7) | lc;
      memo[r] = (lm ? lm : ll) << 7;
    }
  }
  cout << ans;

  return 0;
}
