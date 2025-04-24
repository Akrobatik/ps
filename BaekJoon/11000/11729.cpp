// Title : 하노이 탑 이동 순서
// Link  : https://www.acmicpc.net/problem/11729 
// Time  : 116 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

void Print(int n, int a, int b, int c) {
  if (n == 0) return;

  Print(n - 1, a, c, b);
  cout << a << " " << c << "\n";
  Print(n - 1, b, a, c);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  cout << (1 << n) - 1 << "\n";
  Print(n, 1, 2, 3);

  return 0;
}
