// Title : 경숲길 재개발 2
// Link  : https://www.acmicpc.net/problem/34714 
// Time  : 8 ms
// Memory: 2412 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> arr(n + 2);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  vector<int> lrr, rrr;
  for (int i = 1; i <= n; i++) {
    int h = arr[i];
    if (h == 0) {
      rrr.clear();
      for (int j = i + 1; arr[j]; j++) {
        if (rrr.empty() || rrr.back() < arr[j]) rrr.push_back(arr[j]);
      }

      int val = 1;
      int li = lrr.size() - 1, ri = 0;
      int nr = rrr.size();

      while (li >= 0 && ri < nr) {
        if (lrr[li] < rrr[ri]) {
          --li;
        } else if (lrr[li] > rrr[ri]) {
          ++ri;
        } else {
          val = lrr[li];
          --li, ++ri;
        }
      }

      li = lrr.size() - 1, ri = 0;
      while (li >= 0 && lrr[li] < val) --li;
      while (ri < nr && rrr[ri] < val) ++ri;

      while (li >= 0 || ri < nr) {
        bool dup = false;
        if (li >= 0 && lrr[li] == val) --li, dup = true;
        if (ri < nr && rrr[ri] == val) ++ri, dup = true;
        if (!dup) break;
        ++val;
      }
      h = val;
    }
    arr[i] = h;
    while (!lrr.empty() && lrr.back() <= h) lrr.pop_back();
    lrr.push_back(h);
  }
  cout << *max_element(arr.begin(), arr.end());

  return 0;
}