// Title : 물리를 잘하는 시시포스는 오늘도 우울
// Link  : https://www.acmicpc.net/problem/34700 
// Time  : 140 ms
// Memory: 23732 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  int maxx = *max_element(arr.begin(), arr.end());

  vector<int> axr;
  for (int i = 0; i < n; i++) {
    if (arr[i] == maxx) axr.push_back(i);
  }

  int64_t ans = 0;
  if (axr[0] != 0) {
    for (int i = 0; i < axr[0]; i++) {
      int dt = arr[i + 1] - arr[i];
      if (dt > 0) ans += dt;
    }
  }

  if (axr.back() + 1 != maxx) {
    for (int i = n - 1; i > axr.back(); i--) {
      int dt = arr[i - 1] - arr[i];
      if (dt > 0) ans += dt;
    }
  }

  int na = axr.size();
  vector<int64_t> fwd(n), bwd(n);
  for (int j = 1; j < na; j++) {
    int st = axr[j - 1], en = axr[j];
    for (int i = st + 1; i < en; i++) {
      int dt = arr[i - 1] - arr[i];
      if (dt < 0) dt = 0;
      fwd[i] = fwd[i - 1] + dt;
    }
    for (int i = en - 1; i > st; i--) {
      int dt = arr[i + 1] - arr[i];
      if (dt < 0) dt = 0;
      bwd[i] = bwd[i + 1] + dt;
    }

    int64_t minn = INT64_MAX;
    for (int i = st; i < en; i++) {
      int64_t cur = fwd[i] + bwd[i + 1];
      minn = min<int64_t>(minn, cur);
    }
    ans += minn;
  }

  cout << ans;

  return 0;
}