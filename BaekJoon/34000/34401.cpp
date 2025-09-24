// Title : 놀이기구 줄서기
// Link  : https://www.acmicpc.net/problem/34401 
// Time  : 20 ms
// Memory: 3060 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, p, k;
  cin >> n >> p >> k;

  vector<int> arr[6];
  for (int i = 0; i < n; i++) {
    int t, a;
    cin >> t >> a;
    arr[a].push_back(t);
  }

  queue<int> q[6];
  for (int i = 1; i <= k; i++) {
    auto& a = arr[i];
    sort(a.begin(), a.end());
    for (auto e : a) q[i].push(e);
  }

  auto Empty = [&]() {
    for (int i = 1; i <= k; i++) {
      if (!q[i].empty()) return false;
    }
    return true;
  };

  auto Next = [&](int cur) {
    int minn = INT_MAX;
    for (int i = 1; i <= k; i++) {
      if (q[i].empty()) continue;
      int x = q[i].front();
      minn = min<int>(minn, (x / p) * p);
    }
    return max<int>(minn, cur);
  };

  int64_t sum = 0;
  auto Pick = [&](int cur, int rem) {
    int minn = INT_MAX, mi = 0;
    for (int i = 1; i <= rem; i++) {
      if (q[i].empty() || q[i].front() > cur) continue;
      int x = q[i].front();
      if (minn > x) minn = x, mi = i;
    }

    if (mi) sum += cur - minn, q[mi].pop();
    return mi;
  };

  int cur = 0;
  while (!Empty()) {
    int rem = k;
    cur = Next(cur);
    for (;;) {
      int pick = Pick(cur, rem);
      if (!pick) break;
      rem -= pick;
    }
    cur += p;
  }
  cout << sum;

  return 0;
}
