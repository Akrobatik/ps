// Title : 불꽃놀이
// Link  : https://www.acmicpc.net/problem/32375 
// Time  : 32 ms
// Memory: 3688 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  int cnt = 0;
  vector<int> rems;
  while (n--) {
    int x;
    cin >> x;
    if (x >= k) {
      ++cnt;
    } else {
      rems.push_back(x);
    }
  }

  sort(rems.begin(), rems.end());
  int l = 0, r = rems.size() - 1;
  while (l < r) {
    if (rems[l] + rems[r] >= k) {
      ++cnt, ++l, --r;
    } else {
      ++l;
    }
  }
  cout << (cnt != 0 ? cnt : -1);

  return 0;
}
