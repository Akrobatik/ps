#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  priority_queue<int, vector<int>, greater<>> pq;
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
