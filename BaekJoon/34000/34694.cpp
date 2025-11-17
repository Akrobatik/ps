// Title : 슈퍼 학생
// Link  : https://www.acmicpc.net/problem/34694 
// Time  : 32 ms
// Memory: 3592 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t a, b, w, m;
  cin >> a >> b >> w >> m;

  vector<int64_t> arr(a);
  for (auto& e : arr) cin >> e, --e;
  sort(arr.begin(), arr.end());

  vector<int64_t> axr(w);
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < b; j++) {
      int64_t x;
      cin >> x, --x;
      axr[i] = max<int64_t>(axr[i], x);
    }
  }
  sort(axr.begin(), axr.end(), greater<int64_t>());

  for (int i = 0; i < w; i++) {
    for (int j = b; j < m && !arr.empty(); j++) {
      int64_t x = arr.back();
      arr.pop_back();
      axr[i] = max<int64_t>(axr[i], x);
    }
  }

  cout << accumulate(axr.begin(), axr.end(), 0LL) * 2;

  return 0;
}