// Title : 더 좋은 대화 수단
// Link  : https://www.acmicpc.net/problem/34970 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kArr[] = {1, 3, 2};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cout << kArr[i % 3] << " \n"[i + 1 == n];
  }

  int q = n / 3, r = n % 3;
  int cnt = q * 2 + (r ? 2 : 1);
  cout << cnt << "\n";
  for (int i = 0; i < q; i++) {
    int st = i * 3 + 1;
    cout << st << " " << st + 1 << "\n"
         << st + 1 << " " << st + 1 << "\n";
  }

  int en = n - (r == 2 ? 1 : 0);
  cout << "1 " << en << "\n";
  if (r) cout << en << " " << en;

  return 0;
}