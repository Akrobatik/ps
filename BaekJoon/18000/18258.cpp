// Title : 큐 2
// Link  : https://www.acmicpc.net/problem/18258 
// Time  : 288 ms
// Memory: 10424 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  deque<int> dq;

  while (n--) {
    int x;
    string cmd;
    cin >> cmd;
    switch (cmd[1]) {
      case 'u': {
        cin >> x;
        dq.push_back(x);
      } break;
      case 'o': {
        cout << (dq.empty() ? -1 : (x = dq.front(), dq.pop_front(), x)) << "\n";
      } break;
      case 'i': {
        cout << dq.size() << "\n";
      } break;
      case 'm': {
        cout << dq.empty() << "\n";
      } break;
      case 'r': {
        cout << (dq.empty() ? -1 : dq.front()) << "\n";
      } break;
      case 'a': {
        cout << (dq.empty() ? -1 : dq.back()) << "\n";
      } break;
    }
  }

  return 0;
}