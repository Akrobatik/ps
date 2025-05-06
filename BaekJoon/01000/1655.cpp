// Title : 가운데를 말해요
// Link  : https://www.acmicpc.net/problem/1655 
// Time  : 24 ms
// Memory: 2792 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  priority_queue<int> lt;
  priority_queue<int, vector<int>, greater<int>> gt;

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (i & 1) {
      lt.push(x);
    } else {
      gt.push(x);
    }

    if (i != 1) {
      while (lt.top() > gt.top()) {
        auto l = lt.top(), g = gt.top();
        lt.pop(), gt.pop();
        lt.push(g), gt.push(l);
      }
    }

    cout << lt.top() << "\n";
  }

  return 0;
}
