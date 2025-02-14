#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, c;
  cin >> a >> b;
  int mul = a * b;
  while ((c = a % b)) a = b, b = c;
  cout << b << "\n"
       << mul / b;

  return 0;
}
