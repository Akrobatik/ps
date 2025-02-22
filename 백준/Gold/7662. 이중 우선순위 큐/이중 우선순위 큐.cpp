#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int len = 0;
    map<int, int> mp;
    priority_queue<int> maxq;
    priority_queue<int, vector<int>, greater<>> minq;

    int n;
    cin >> n;
    while (n--) {
      char c;
      int v;
      cin >> c >> v;
      if (c == 'I') {
        ++len;
        ++mp[v];
        maxq.push(v);
        minq.push(v);
      } else {
        if (len == 0) continue;
        --len;
        if (v == 1) {
          for (;;) {
            int vv = maxq.top();
            maxq.pop();
            if (mp.contains(vv)) {
              if (--mp[vv] == 0) mp.erase(vv);
              break;
            }
          }
        } else {
          for (;;) {
            int vv = minq.top();
            minq.pop();
            if (mp.contains(vv)) {
              if (--mp[vv] == 0) mp.erase(vv);
              break;
            }
          }
        }
      }
    }

    if (len == 0) {
      cout << "EMPTY\n";
    } else {
      cout << (--mp.end())->first << " " << mp.begin()->first << "\n";
    }
  }

  return 0;
}
