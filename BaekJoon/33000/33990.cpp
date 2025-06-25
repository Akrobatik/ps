// Title : 3대 512
// Link  : https://www.acmicpc.net/problem/33990 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int best = INT_MAX;
  while (n--) {
    int a, b, c;
    cin >> a >> b >> c;
    int sum = a + b + c;
    if (sum < 512) continue;
    best = min<int>(best, sum);
  }
  cout << (best != INT_MAX ? best : -1);

  return 0;
}
