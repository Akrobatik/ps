// Title : Rope Folding
// Link  : https://www.acmicpc.net/problem/5902 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, l;
  cin >> n >> l;
  l <<= 1;

  vector<int> arr(n);
  for (auto& e : arr) cin >> e, e <<= 1;
  sort(arr.begin(), arr.end());

  int cnt = 0;
  vector<int> axr, bxr;
  for (int i = 1; i < l; i++) {
    axr.clear(), bxr.clear();
    int limit = min<int>(i, l - i);

    for (auto e : arr) {
      if (abs(i - e) <= limit) {
        if (e < i) {
          axr.push_back(i - e);
        } else if (e > i) {
          bxr.push_back(e - i);
        }
      }
    }

    int na = axr.size(), nb = bxr.size();
    if (na != nb) continue;

    bool ok = true;
    for (int j = 0; ok && j < na; j++) {
      ok = (axr[j] == bxr[na - j - 1]);
    }
    cnt += ok;
  }
  cout << cnt;

  return 0;
}