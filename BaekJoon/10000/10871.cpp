// Title : X보다 작은 수
// Link  : https://www.acmicpc.net/problem/10871
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;
  while (n--) {
    int v;
    cin >> v;
    if (v < x) cout << v << " ";
  }

  return 0;
}
