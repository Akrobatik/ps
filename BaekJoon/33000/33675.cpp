// Title : L－트로미노 타일링
// Link  : https://www.acmicpc.net/problem/33675
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
    if (n & 1) {
      cout << "0\n";
    } else {
      cout << (1ll << (n >> 1)) << "\n";
    }
  }

  return 0;
}
