#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  priority_queue<int, vector<int>, greater<>> pq1, pq2;
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    if (c == '1') {
      pq1.push(i);
    } else {
      pq2.push(i);
    }
  }

  int out = 0;
  int cnt = 0;
  while (out != n) {
    int c = 0;
    if (!pq1.empty()) {
      if (pq1.top() - out < k) {
        pq1.pop();
        ++c;
      }
    }
    if (!pq2.empty()) {
      if (pq2.top() - out < k) {
        pq2.pop();
        ++c;
      }
    }
    out += c;
    ++cnt;
  }
  cout << cnt;

  return 0;
}
