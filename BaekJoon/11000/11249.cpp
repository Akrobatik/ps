// Title : Chasing
// Link  : https://www.acmicpc.net/problem/11249 
// Time  : 40 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int64_t n, a, b;
    cin >> n >> a >> b, --a, --b;
    if (a > b) b += n;
    int64_t dt = b - a;
    cout << (dt != n - 1 ? dt : 1 % n) << "\n";
  }

  return 0;
}