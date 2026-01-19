// Title : $\exists99$
// Link  : https://www.acmicpc.net/problem/35144 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int64_t GCD(int64_t a, int64_t b) {
  while (b) a %= b, swap(a, b);
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t a, b;
  cin >> a >> b;
  if (a > b) swap(a, b);

  if (a == b) {
    cout << "INF";
  } else {
    int64_t p = a * a, q = b - a;
    int64_t g = GCD(p, q);
    cout << p / g << " " << q / g << "\n";
  }

  return 0;
}