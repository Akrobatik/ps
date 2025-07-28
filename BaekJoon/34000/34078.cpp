// Title : 벨과 와이즈의 가게 홍보
// Link  : https://www.acmicpc.net/problem/34078 
// Time  : 24 ms
// Memory: 6084 KB

#include <bits/stdc++.h>

using namespace std;

int Count(const vector<int>& org, const vector<int>& dst) {
  int n = org.size();
  vector<int> pos(n);
  for (int i = 1; i < n; i++) {
    pos[org[i]] = i;
  }

  vector<int> rev(n);
  for (int i = 1; i < n; i++) {
    rev[i] = pos[dst[i]];
  }

  vector<bool> used(n);
  int cnt = 0;
  for (int i = 1; i < n; i++) {
    if (used[i]) continue;
    ++cnt;
    int cur = i;
    do {
      used[cur] = true;
      cur = rev[cur];
    } while (!used[cur]);
  }
  return n - cnt - 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) cin >> arr[i];

  vector<int> fwd(n + 1), bwd(n + 1);
  iota(fwd.begin(), fwd.end(), 0);
  iota(bwd.rbegin(), bwd.rend(), 1);

  int minn = min<int>(Count(arr, fwd), Count(arr, bwd));
  cout << n - 2 << " " << minn;

  return 0;
}
