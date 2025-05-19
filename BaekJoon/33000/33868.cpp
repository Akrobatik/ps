// Title : 스티커 나눠주기
// Link  : https://www.acmicpc.net/problem/33868 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int bt = 0, bb = INT_MAX;
  while (n--) {
    int t, b;
    cin >> t >> b;
    bt = max<int>(bt, t);
    bb = min<int>(bb, b);
  }

  cout << (bt * bb % 7) + 1;

  return 0;
}
