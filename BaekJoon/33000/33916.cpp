// Title : 서로소 조합
// Link  : https://www.acmicpc.net/problem/33916 
// Time  : 84 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 5000;

bool seive[kMax + 1];
vector<int> primes;

int Count(int x, int p) {
  int cnt = 0;
  while (x) x /= p, cnt += x;
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 2; i <= kMax; i++) {
    if (!seive[i]) primes.push_back(i);
    for (auto p : primes) {
      if (i * p > kMax) break;
      seive[i * p] = true;
      if (i % p == 0) break;
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int n1, r1, n2, r2;
    cin >> n1 >> r1 >> n2 >> r2;

    if (r1 > n1 - r1) r1 = n1 - r1;
    if (r2 > n2 - r2) r2 = n2 - r2;

    if (r1 == 0 || r2 == 0) {
      cout << "1\n";
      continue;
    }

    bool ok = true;
    for (auto p : primes) {
      if (p > n1 || p > n2) break;

      int c1 = Count(n1, p) - Count(r1, p) - Count(n1 - r1, p);
      int c2 = Count(n2, p) - Count(r2, p) - Count(n2 - r2, p);
      if (c1 > 0 && c2 > 0) {
        ok = false;
        break;
      }
    }
    cout << ok << "\n";
  }

  return 0;
}