// Title : 대칭 XOR
// Link  : https://www.acmicpc.net/problem/34328 
// Time  : 24 ms
// Memory: 3232 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  if (n & 1) {
    cout << (n == 1 ? "1" : "-1");
    return 0;
  }

  int key = n | 1;
  deque<int> dq;
  vector<bool> used(n + 1);
  for (int i = 1; i <= n; i++) {
    if (used[i]) continue;
    int l = i, r = key ^ i;
    if (r > n) {
      cout << "-1";
      return 0;
    }
    used[l] = used[r] = true;
    dq.push_front(l), dq.push_back(r);
  }

  for (auto e : dq) cout << e << " ";

  return 0;
}
