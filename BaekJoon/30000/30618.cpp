// Title : donstructive
// Link  : https://www.acmicpc.net/problem/30618 
// Time  : 12 ms
// Memory: 2944 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  deque<int> dq;
  for (int i = n; i >= 1; i--) {
    if (i & 1) {
      dq.push_back(i);
    } else {
      dq.push_front(i);
    }
  }

  for (auto e : dq) cout << e << " ";

  return 0;
}