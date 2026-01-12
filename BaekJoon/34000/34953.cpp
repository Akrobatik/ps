// Title : SSHS 문자열
// Link  : https://www.acmicpc.net/problem/34953 
// Time  : 8 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cout << "SSH"[i % 3];
  }

  return 0;
}