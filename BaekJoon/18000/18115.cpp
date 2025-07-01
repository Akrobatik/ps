// Title : 카드 놓기
// Link  : https://www.acmicpc.net/problem/18115 
// Time  : 200 ms
// Memory: 37212 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  list<int> ls;
  int idx = 0;
  for (auto e : views::reverse(arr)) {
    if (e == 1) {
      ls.push_front(++idx);
    } else if (e == 2) {
      ls.insert(next(ls.begin()), ++idx);
    } else {
      ls.push_back(++idx);
    }
  }

  for (auto e : ls) cout << e << " ";

  return 0;
}
