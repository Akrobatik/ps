// Title : 1로 만들기 3
// Link  : https://www.acmicpc.net/problem/27440 
// Time  : 4 ms
// Memory: 3192 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  cin >> n;

  queue<int64_t> q;
  unordered_set<int64_t> hs;

  auto Push = [&](int64_t x) {
    if (hs.contains(x)) return;
    hs.insert(x);
    q.push(x);
  };

  Push(n);
  for (int i = 0;; i++) {
    int nq = q.size();
    while (nq--) {
      int64_t x = q.front();
      q.pop();

      if (x == 1) {
        cout << i;
        return 0;
      }

      if (x % 3 == 0) Push(x / 3);
      if (x % 2 == 0) Push(x / 2);
      Push(x - 1);
    }
  }

  return 0;
}