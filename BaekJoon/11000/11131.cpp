// Title : Balancing Weights
// Link  : https://www.acmicpc.net/problem/11131
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
    int64_t sum = 0;
    while (n--) {
      int x;
      cin >> x;
      sum += x;
    }
    if (sum == 0) {
      cout << "Equilibrium\n";
    } else if (sum < 0) {
      cout << "Left\n";
    } else {
      cout << "Right\n";
    }
  }

  return 0;
}
