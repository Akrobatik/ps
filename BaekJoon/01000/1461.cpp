// Title : 도서관
// Link  : https://www.acmicpc.net/problem/1461 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  int maxx = 0;
  vector<int> lrr, rrr;
  while (n--) {
    int x;
    cin >> x;
    if (x > 0) {
      rrr.push_back(x);
    } else {
      lrr.push_back(-x);
    }
    maxx = max<int>(maxx, abs(x));
  }

  sort(lrr.begin(), lrr.end(), greater<int>());
  sort(rrr.begin(), rrr.end(), greater<int>());

  int64_t sum = 0;
  for (int i = 0; i < lrr.size(); i += m) {
    sum += (lrr[i] << 1);
  }
  for (int i = 0; i < rrr.size(); i += m) {
    sum += (rrr[i] << 1);
  }
  cout << sum - maxx;

  return 0;
}