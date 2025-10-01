// Title : 장기
// Link  : https://www.acmicpc.net/problem/32684 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kTable[] = {13, 7, 5, 3, 3, 2};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a = 0, b = 0;
  for (int i = 0; i < 6; i++) {
    int x;
    cin >> x;
    a += kTable[i] * x;
  }
  for (int i = 0; i < 6; i++) {
    int x;
    cin >> x;
    b += kTable[i] * x;
  }
  cout << (a > b + 1 ? "cocjr0208" : "ekwoo");

  return 0;
}