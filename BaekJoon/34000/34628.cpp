// Title : Triple Removal
// Link  : https://www.acmicpc.net/problem/34628 
// Time  : 76 ms
// Memory: 4960 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> arr, fwd, memo;

void Solve() {
  int n, q;
  cin >> n >> q;

  arr.resize(n + 1), fwd.resize(n + 1);
  arr[0] = fwd[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    fwd[i] = fwd[i - 1] + arr[i];
  }

  int idx = 1;
  memo.resize(n + 1);
  while (idx <= n) {
    int nxt = idx, key = arr[idx];
    while (nxt <= n && arr[nxt] == key) ++nxt, key ^= 1;
    for (int i = idx; i < nxt; i++) memo[i] = idx;
    idx = nxt;
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    int all = r - l + 1;
    int ones = fwd[r] - fwd[l - 1], zeros = all - ones;
    cout << (ones % 3 == 0 && zeros % 3 == 0 ? (all / 3) + (memo[r] <= l) : -1) << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) Solve();

  return 0;
}