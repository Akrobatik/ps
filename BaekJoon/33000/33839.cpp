// Title : 분탕의 신 아이보리 3
// Link  : https://www.acmicpc.net/problem/33839 
// Time  : 24 ms
// Memory: 4248 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int64_t> fwd(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> fwd[i];
    fwd[i] += fwd[i - 1];
  }

  deque<int> dq;

  int64_t bx = 0;
  int bl = 2, br = 1;
  if (n == 1) bx = fwd[n], bl = br = 1;

  for (int r = 1; r <= n; r++) {
    while (!dq.empty() && fwd[dq.back()] > fwd[r - 1]) dq.pop_back();
    dq.push_back(r - 1);

    int limit = max<int>(r - k - 1, 0);
    while (dq.front() < limit) dq.pop_front();

    int p = dq.front();
    int64_t cur = fwd[r] - fwd[p];
    int l = p + 1;
    if (bx < cur) {
      bx = cur;
      bl = l;
      br = r;
    } else if (bx == cur) {
      if (l < bl || (l == bl && r < br)) {
        bl = l;
        br = r;
      }
    }
  }

  cout << bx * 2 - fwd[n] << "\n"
       << bl << " " << br << "\n";

  return 0;
}
