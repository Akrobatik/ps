// Title : 과제 안 내신 분..?
// Link  : https://www.acmicpc.net/problem/5597 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  bool check[31] = {};
  for (int i = 0; i < 28; i++) {
    int x;
    cin >> x;
    check[x] = true;
  }

  for (int i = 1; i <= 30; i++) {
    if (check[i]) continue;
    cout << i << "\n";
  }

  return 0;
}
