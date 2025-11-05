// Title : 가희와 노선 건설 놀이 2
// Link  : https://www.acmicpc.net/problem/34669 
// Time  : 32 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int64_t a, b;
    cin >> a >> b;
    cout << a * b << " " << a / b << "\n";
  }

  return 0;
}