// Title : 인버전 과제
// Link  : https://www.acmicpc.net/problem/34886 
// Time  : 8 ms
// Memory: 13808 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  int l = 1, cur = m;
  for (int i = 1; cur && i <= n; i++) {
    cout << l << " " << i << endl;
    int nxt;
    cin >> nxt;
    if (cur > nxt) {
      cur = nxt;
      l = i + 1;
    } else {
      l = i;
    }
  }

  return 0;
}