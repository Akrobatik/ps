// Title : 약수 구하기
// Link  : https://www.acmicpc.net/problem/2501 
// Time  : 0 ms
// Memory: 2180 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> f;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      f.push_back(i);
      if (i * i != n) f.push_back(n / i);
    }
  }
  sort(f.begin(), f.end());
  f.resize(k);
  cout << f[k - 1];

  return 0;
}
