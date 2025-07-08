// Title : 덱 2
// Link  : https://www.acmicpc.net/problem/28279 
// Time  : 156 ms
// Memory: 6304 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  deque<int> dq;

  while (n--) {
    int cmd, x;
    cin >> cmd;
    switch (cmd) {
      case 1: {
        cin >> x;
        dq.push_front(x);
      } break;
      case 2: {
        cin >> x;
        dq.push_back(x);
      } break;
      case 3: {
        cout << (dq.empty() ? -1 : (x = dq.front(), dq.pop_front(), x)) << "\n";
      } break;
      case 4: {
        cout << (dq.empty() ? -1 : (x = dq.back(), dq.pop_back(), x)) << "\n";
      } break;
      case 5: {
        cout << dq.size() << "\n";
      } break;
      case 6: {
        cout << dq.empty() << "\n";
      } break;
      case 7: {
        cout << (dq.empty() ? -1 : dq.front()) << "\n";
      } break;
      case 8: {
        cout << (dq.empty() ? -1 : dq.back()) << "\n";
      } break;
    }
  }

  return 0;
}