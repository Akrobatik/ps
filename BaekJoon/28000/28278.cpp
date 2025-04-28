// Title : 스택 2
// Link  : https://www.acmicpc.net/problem/28278 
// Time  : 128 ms
// Memory: 8292 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> stk;

  int n;
  cin >> n;
  while (n--) {
    int op;
    cin >> op;
    switch (op) {
      case 1: {
        int x;
        cin >> x;
        stk.push_back(x);
      } break;

      case 2: {
        if (stk.empty()) {
          cout << "-1\n";
        } else {
          cout << stk.back() << "\n";
          stk.pop_back();
        }
      } break;

      case 3: {
        cout << stk.size() << "\n";
      } break;

      case 4: {
        cout << stk.empty() << "\n";
      } break;

      case 5: {
        cout << (stk.empty() ? -1 : stk.back()) << "\n";
      } break;
    }
  }

  return 0;
}
