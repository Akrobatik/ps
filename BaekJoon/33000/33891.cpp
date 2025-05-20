// Title : 구간 단속 종료 지점입니다
// Link  : https://www.acmicpc.net/problem/33891 
// Time  : 520 ms
// Memory: 66752 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, en;
  cin >> n >> m >> en;
  vector<tup> arr(n);
  vector<int> memo = {0, en};
  for (auto& [s, e, v] : arr) {
    cin >> s >> e >> v;
    memo.push_back(s), memo.push_back(e);
  }
  sort(arr.begin(), arr.end());
  sort(memo.begin(), memo.end());
  memo.erase(unique(memo.begin(), memo.end()), memo.end());

  auto Get = [&](int x) -> int {
    return lower_bound(memo.begin(), memo.end(), x) - memo.begin();
  };

  vector<vector<pair<int, int>>> conds(memo.size());
  for (auto& [s, e, v] : arr) {
    s = Get(s), e = Get(e);
    conds[e].push_back({s, v});
  }

  vector<long double> times(memo.size());
  int px = 0;
  long double pt = 0.0L;
  for (int i = 1; i < memo.size(); i++) {
    int cx = memo[i];
    long double ct = pt + (long double)(cx - px) / (long double)m;
    
    for (auto [s, v] : conds[i]) {
      ct = max<long double>(ct, times[s] + (long double)(cx - memo[s]) / (long double)v);
    }

    times[i] = ct;
    px = cx, pt = ct;
  }

  cout << setprecision(6) << fixed << times.back();

  return 0;
}