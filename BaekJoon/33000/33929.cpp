// Title : 예쁘게 출력한 이진 트리
// Link  : https://www.acmicpc.net/problem/33929 
// Time  : 52 ms
// Memory: 19180 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> arr, ans;
vector<vector<int>> pos;

void Traverse(int l, int r, int x, int par, int dir) {
  if (l > r) return;

  auto& p = pos[x];
  if (dir == 1) {
    auto it = lower_bound(p.begin(), p.end(), l);
    if (it != p.end() && *it <= r) {
      int nxt = *it;
      ans[nxt] = par + 1;
      Traverse(nxt + 1, r, x, nxt, 1);
      Traverse(l, nxt - 1, x + 1, nxt, -1);
    }
  } else {
    auto it = lower_bound(p.rbegin(), p.rend(), r, greater<>());
    if (it != p.rend() && *it >= l) {
      int nxt = *it;
      ans[nxt] = par + 1;
      Traverse(nxt + 1, r, x + 1, nxt, 1);
      Traverse(l, nxt - 1, x, nxt, -1);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  arr.resize(n), pos.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    pos[arr[i]].push_back(i);
  }

  for (int i = 0; i < n; i++) {
    sort(pos[i].begin(), pos[i].end());
  }

  if (pos[0].size() != 1) {
    cout << "-1";
    return 0;
  }

  int root = pos[0][0];

  ans.assign(n, -1);
  ans[root] = 0;
  Traverse(root + 1, n - 1, 1, root, 1);
  Traverse(0, root - 1, 1, root, -1);

  bool ok = true;
  for (int i = 0; ok && i < n; i++) {
    ok = (ans[i] != -1);
  }

  if (ok) {
    for (auto e : ans) cout << e << " ";
  } else {
    cout << "-1";
  }

  return 0;
}