// Title : 연속부분최대곱
// Link  : https://www.acmicpc.net/problem/2670 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  double maxx = 0.0, cur = 0.0;
  while (n--) {
    double x;
    cin >> x;
    cur = max<double>(cur, 1.0) * x;
    maxx = max<double>(maxx, cur);
  }
  cout << setprecision(3) << fixed << maxx;

  return 0;
}
