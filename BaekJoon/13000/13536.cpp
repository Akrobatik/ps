// Title : 괄호 부분 문자열 쿼리
// Link  : https://www.acmicpc.net/problem/13536 
// Time  : 56 ms
// Memory: 11872 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1 << 20;
int tree[kMax << 1];

int Query(int l, int r) {
  int sz = r - l;
  int lv = tree[l + kMax], rv = tree[r + kMax];
  int minn = INT_MAX;
  for (l += kMax, r += kMax + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) minn = min<int>(minn, tree[l++]);
    if (r & 1) minn = min<int>(minn, tree[--r]);
  }
  return sz - (lv - minn) - (rv - minn);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size();

  int cur = 0;
  for (int i = 0; i < n; i++) {
    cur += (s[i] == '(' ? 1 : -1);
    tree[i + kMax + 1] = cur;
  }

  for (int i = kMax - 1; i > 0; i--) {
    tree[i] = min<int>(tree[i << 1], tree[(i << 1) + 1]);
  }

  int m;
  cin >> m;
  while (m--) {
    int l, r;
    cin >> l >> r;
    cout << Query(l - 1, r) << "\n";
  }

  return 0;
}
