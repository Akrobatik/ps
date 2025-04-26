// Title : 쌍의 합
// Link  : https://www.acmicpc.net/problem/5217 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << "Pairs for " << n << ":";

    int half = (n + 1) >> 1;
    for (int i = 1; i < half; i++) {
      cout << (i == 1 ? " " : ", ") << i << " " << n - i;
    }
    cout << "\n";
  }

  return 0;
}
