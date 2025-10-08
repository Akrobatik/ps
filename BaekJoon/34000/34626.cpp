// Title : Increase or Smash
// Link  : https://www.acmicpc.net/problem/34626 
// Time  : 4 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

void Solve() {
  bool used[101] = {};

  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    used[x] = true;
  }

  int cnt = 0;
  for (int i = 1; i <= 100; i++) cnt += used[i];
  cout << (cnt << 1) - 1 << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) Solve();

  return 0;
}