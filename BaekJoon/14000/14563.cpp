// Title : 완전수
// Link  : https://www.acmicpc.net/problem/14563
// Time  : 4 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i < n; i++) {
      if (n % i == 0) sum += i;
    }
    if (n == sum) {
      cout << "Perfect\n";
    } else if (n > sum) {
      cout << "Deficient\n";
    } else {
      cout << "Abundant\n";
    }
  }

  return 0;
}
