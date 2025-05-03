// Title : 별 찍기 - 5
// Link  : https://www.acmicpc.net/problem/2442 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int l = n - i - 1, r = n + i - 1;
    for (int j = 0; j < l; j++) cout << " ";
    for (int j = l; j <= r; j++) cout << "*";
    cout << "\n";
  }

  return 0;
}
