// Title : 간단한 동전 문제 (Easy)
// Link  : https://www.acmicpc.net/problem/33938 
// Time  : 0 ms
// Memory: 2032 KB

#include <bits/stdc++.h>

using namespace std;

int _memo[2001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto memo = _memo + 1000;

  int n, m;
  cin >> n >> m;
  if (m == 0) {
    cout << "0";
    return 0;
  }
  if (n == 0) {
    cout << "-1";
    return 0;
  }

  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end());

  queue<int> q;
  q.push(0);

  int r = max<int>({abs(m), abs(arr[0]), abs(arr.back())}), l = -r;
  auto Push = [&](int x, int d) {
    if (x < l || x > r || memo[x]) return;
    memo[x] = d;
    q.push(x);
  };

  for (int i = 0; !q.empty(); i++) {
    int nq = q.size();
    while (nq--) {
      auto x = q.front();
      q.pop();

      for (auto v : arr) {
        Push(x + v, i + 1);
      }
    }
  }

  cout << (memo[m] ? memo[m] : -1);

  return 0;
}
