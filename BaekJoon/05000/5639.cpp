// Title : 이진 검색 트리
// Link  : https://www.acmicpc.net/problem/5639
// Time  : 280 ms
// Memory: 6120 KB

#include <bits/stdc++.h>

using namespace std;

int memo[1000000];

void Post(int* b, int* e) {
  if (b >= e) return;
  int* p = find_if(b + 1, e, [&](int v) { return v > *b; });
  Post(b + 1, p);
  Post(p, e);
  cout << *b << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n = 0;
  int v;
  while (cin >> v) {
    memo[n++] = v;
  }
  Post(memo, memo + n);

  return 0;
}
