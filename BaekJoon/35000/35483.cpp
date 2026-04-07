// Title : 루미상관 수
// Link  : https://www.acmicpc.net/problem/35483 
// Time  : 88 ms
// Memory: 7172 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  set<int> st;
  for (int i = 1; i < 10; i++) {
    st.insert(i);
  }

  for (int i = 1; i < 10000; i++) {
    int x = 1;
    while (x * 10 <= i) x *= 10;
    x *= 10;

    st.insert(i * x + i);
    for (int j = 0; j < 10; j++) {
      st.insert((i * 10 + j) * x + i);
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int cnt = 0;
    for (auto e : st) {
      cnt += st.contains(n - e);
    }
    cout << cnt << "\n";
  }

  return 0;
}