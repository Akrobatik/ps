// Title : 단순한 문제 （Large）
// Link  : https://www.acmicpc.net/problem/25487
// Time  : 200 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
		cout << min<int>({a, b, c}) << "\n";
  }

  return 0;
}
