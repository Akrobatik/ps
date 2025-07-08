// Title : 풍선 터뜨리기
// Link  : https://www.acmicpc.net/problem/2346 
// Time  : 0 ms
// Memory: 2152 KB

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
  for (int i = 0; i < n; i++) ls.push_back(i);

  auto it = ls.begin();
  for (;;) {
    int x = *it;
    cout << x + 1 << " ";
    if (it = ls.erase(it); it == ls.end()) it = ls.begin(); 
    if (it == ls.end()) break;
    int d = arr[x], l = ls.size();
    if (d > 0) --d;
    if ((d %= l) < 0) d += l;
    while (d--) {
      if (++it == ls.end()) it = ls.begin();
    }
  }

  return 0;
}