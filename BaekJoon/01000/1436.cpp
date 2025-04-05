// Title : 영화감독 숌
// Link  : https://www.acmicpc.net/problem/1436
// Time  : 4 ms
// Memory: 2100 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int table[50000];
  auto ptr = table;
  for (int i = 0; i <= 9999; i++) {
    char s[4];
    int v = i;
    for (int j = 3; j >= 0; j--) {
      s[j] = '0' + v % 10;
      v /= 10;
    }

    string_view sv(s, s + 4);
    for (int j = 0; j < 5; j++) {
      string ss;
      ss.reserve(7);
      ss.append(sv.substr(0, j));
      ss.append("666");
      ss.append(sv.substr(j));
      table[i * 5 + j] = stoi(ss);
    }
  }
  sort(table, table + 50000);
  unique(table, table + 50000);

  int n;
  cin >> n;
  cout << table[n - 1];

  return 0;
}
