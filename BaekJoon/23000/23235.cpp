// Title : The Fastest Sorting Algorithm In The World
// Link  : https://www.acmicpc.net/problem/23235 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  int t = 0;
  while (cin >> n && n) {
    int x;
    while (n--) cin >> x;
    cout << "Case " << ++t << ": Sorting... done!\n";
  }

  return 0;
}
