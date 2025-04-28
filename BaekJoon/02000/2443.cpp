// Title : 별 찍기 - 6
// Link  : https://www.acmicpc.net/problem/2443 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int cnt = ((n - i) << 1) - 1;
    for (int j = 0; j < i; j++) cout << ' ';
    for (int j = 0; j < cnt; j++) cout << '*';
    cout << '\n';
  }

  return 0;
}
