// Title : 하이터치☆메모리
// Link  : https://www.acmicpc.net/problem/34031 
// Time  : 4 ms
// Memory: 4172 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s1, s2;
  cin >> s1 >> s2;

  int limit = max<int>(s1.size(), s2.size());
  vector<int> fwd(limit + 1), bwd(limit + 1);

  int cur = 0;
  for (auto c : s1) {
    cur += (c == '(' ? 1 : -1);
    if (cur < 0) break;
    ++fwd[cur];
  }

  int maxx = 0;
  cur = 0;
  for (auto c : s2) {
    cur += (c == ')' ? 1 : -1);
    maxx = max<int>(maxx, cur);
    if (maxx == cur) ++bwd[cur];
  }

  int64_t sum = 0;
  for (int i = 0; i <= limit; i++) {
    sum += (int64_t)fwd[i] * bwd[i];
  }
  cout << sum;

  return 0;
}
