// Title : 최대 힙
// Link  : https://www.acmicpc.net/problem/11279
// Time  : 16 ms
// Memory: 2916 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  priority_queue<int> pq;
  while (n--) {
    int v;
    cin >> v;
    if (v) {
      pq.push(v);
    } else {
      if (pq.empty()) {
        cout << "0\n";
      } else {
        cout << pq.top() << "\n";
        pq.pop();
      }
    }
  }

  return 0;
}
