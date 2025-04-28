// Title : 하노이 탑 K
// Link  : https://www.acmicpc.net/problem/23250 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

void Traverse(int n, int64_t r, int a, int b, int c) {
  int64_t mid = 1ll << (n - 1);
  if (r < mid) {
    Traverse(n - 1, r, a, c, b);
  } else if (r == mid) {
    cout << a << " " << c;
    exit(0);
  } else {
    Traverse(n - 1, r - mid, b, a, c);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, k;
  cin >> n >> k;
  Traverse(n, k, 1, 2, 3);

  return 0;
}
