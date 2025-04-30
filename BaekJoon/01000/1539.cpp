// Title : 이진 검색 트리
// Link  : https://www.acmicpc.net/problem/1539 
// Time  : 140 ms
// Memory: 13772 KB

#include <bits/stdc++.h>

using namespace std;

map<int, int> memo;

int GetHeight(int x) {
  int maxx = 0;
  if (auto it = memo.upper_bound(x); it != memo.end()) {
    maxx = max<int>(maxx, it->second);
    if (it != memo.begin()) maxx = max<int>(maxx, (--it)->second);
  } else if (!memo.empty()) {
    maxx = max<int>(maxx, memo.rbegin()->second);
  }
  return memo[x] = maxx + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int64_t sum = 0;
  while (n--) {
    int x;
    cin >> x;
    sum += GetHeight(x);
  }
  cout << sum;

  return 0;
}
