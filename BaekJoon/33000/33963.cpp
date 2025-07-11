// Title : 돈복사
// Link  : https://www.acmicpc.net/problem/33963 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  cin >> n;
  int sz = to_string(n).size();

  int cnt = 0;
  while (sz == to_string(n).size()) n <<= 1, ++cnt;
  cout << cnt - 1;

  return 0;
}
