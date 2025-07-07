// Title : 배수와 약수
// Link  : https://www.acmicpc.net/problem/5086 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b;
  while (cin >> a >> b && a && b) {
    if (a % b == 0) {
      cout << "multiple\n";
      continue;
    }
    if (b % a == 0) {
      cout << "factor\n";
      continue;
    }
    cout << "neither\n";
  }

  return 0;
}
