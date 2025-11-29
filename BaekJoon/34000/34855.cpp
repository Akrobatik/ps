// Title : 비밀번호 전달하기
// Link  : https://www.acmicpc.net/problem/34855 
// Time  : 4 ms
// Memory: 13676 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  int arr[6];
  for (auto& e : arr) cin >> e, --e;

  int chk[64] = {};
  for (auto e : arr) chk[e] = 1;

  for (int i = 0; i < 6; i++) {
    int pass = 0, key = 1 << i;
    for (auto e : arr) {
      pass |= chk[e ^ key];
    }
    if (pass) continue;
    for (auto e : arr) cout << (e ^ key) + 1 << " ";
    break;
  }

  return 0;
}