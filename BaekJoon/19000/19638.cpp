// Title : 센티와 마법의 뿅망치
// Link  : https://www.acmicpc.net/problem/19638 
// Time  : 20 ms
// Memory: 2916 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, h, t;
  cin >> n >> h >> t;

  priority_queue<int> pq;
  while (n--) {
    int x;
    cin >> x;
    pq.push(x);
  }

  int cnt;
  for (cnt = 0; h <= pq.top() && pq.top() != 1 && cnt < t; cnt++) {
    int x = pq.top();
    pq.pop();
    pq.push(x >> 1);
  }

  if (h > pq.top()) {
    cout << "YES\n";
    cout << cnt;
  } else {
    cout << "NO\n";
    cout << pq.top();
  }

  return 0;
}
