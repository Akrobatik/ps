// Title : 디딤돌 장학금
// Link  : https://www.acmicpc.net/problem/34552 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int table[11];
  for (auto& e : table) cin >> e;

  int sum = 0;

  int n;
  cin >> n;
  while (n--) {
    int b, s;
    long double fl;
    cin >> b >> fl >> s;
    int l = (int)(fl * 100.0L);

    sum += (s >= 17 && l >= 200 ? table[b] : 0);
  }
  cout << sum;

  return 0;
}