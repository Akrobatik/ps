// Title : 간판 만들기
// Link  : https://www.acmicpc.net/problem/34894 
// Time  : 40 ms
// Memory: 2912 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kInf = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;

  array<int64_t, 6> arr;
  arr.fill(kInf);
  arr[0] = 0;

  auto Get = [](char c) {
    if (c == 'U') return 1;
    if (c == 'O') return 2;
    if (c == 'S') return 3;
    if (c == 'P') return 4;
    return 5;
  };

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    int v = Get(s[i]);
    arr[v] = min<int64_t>(arr[v], arr[v - 1] + x);
  }

  cout << (arr[5] != kInf ? arr[5] : -1);

  return 0;
}