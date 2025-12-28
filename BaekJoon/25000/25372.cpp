// Title : 성택이의 은밀한 비밀번호
// Link  : https://www.acmicpc.net/problem/25372 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    cout << (6 <= n && n <= 9 ? "yes\n" : "no\n");
  }

  return 0;
}