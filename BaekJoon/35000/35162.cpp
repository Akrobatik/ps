// Title : KCPC 스티커 만들기
// Link  : https://www.acmicpc.net/problem/35162 
// Time  : 8 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int k, c, p;
    cin >> k >> c >> p;

    if (k == 0) {
      if (p == 0) {
        cout << (c >= 2 ? "Y\n" : "N\n");
      } else if (p == 1) {
        cout << (c != 0 ? "Y\n" : "N\n");
      } else {
        cout << "Y\n";
      }
    } else if (k == 1) {
      if (p == 0) {
        cout << (c != 0 ? "Y\n" : "N\n");
      } else if (p == 1) {
        cout << (c != 0 ? "Y\n" : "N\n");
      } else {
        cout << "Y\n";
      }
    } else if (k == 2) {
      if (p == 0) {
        cout << (c >= 2 ? "Y\n" : "N\n");
      } else if (p == 1) {
        cout << (c != 0 ? "Y\n" : "N\n");
      } else {
        cout << "Y\n";
      }
    } else {
      if (p == 0) {
        cout << (c >= 2 ? "Y\n" : "N\n");
      } else if (p == 1) {
        cout << (c != 0 ? "Y\n" : "N\n");
      } else {
        cout << "Y\n";
      }
    }
  }

  return 0;
}