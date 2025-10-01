// Title : Загадка древних Ассасинов
// Link  : https://www.acmicpc.net/problem/28987 
// Time  : 4 ms
// Memory: 2300 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  int cnt[10] = {};
  for (auto c : s) {
    ++cnt[c - '0'];
  }

  int sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += cnt[i] * i;
  }

  while (sum % 3) {
    int rem = sum % 3;
    int idx = -1;
    for (int x : {rem, rem ^ 3}) {
      for (int i = x; i < 10; i += 3) {
        if (cnt[i] == 0) continue;
        idx = i;
        break;
      }
      if (idx != -1) break;
    }

    --cnt[idx], sum -= idx;
  }

  for (int i = 9; i >= 0; i--) {
    while (cnt[i]--) cout << (char)(i + '0');
  }

  return 0;
}