// Title : 학점계산
// Link  : https://www.acmicpc.net/problem/2754 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  char a;
  cin >> a;

  int x = ('A' <= a && a <= 'D' ? 69 - a : 0) * 10;
  if (x) {
    char b;
    cin >> b;
    if (b == '+') x += 3;
    if (b == '-') x -= 3;
  }

  cout << (x / 10) << "." << (x % 10);

  return 0;
}