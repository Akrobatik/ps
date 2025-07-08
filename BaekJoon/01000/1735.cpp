// Title : 분수 합
// Link  : https://www.acmicpc.net/problem/1735 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b) {
  while (b) a %= b, swap(a, b);
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int p1, q1, p2, q2;
  cin >> p1 >> q1 >> p2 >> q2;
  int np = p1 * q2 + p2 * q1, nq = q1 * q2;
  int g = GCD(np, nq);
  np /= g, nq /= g;
  cout << np << " " << nq;

  return 0;
}
