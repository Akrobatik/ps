// Title : 노래 오래 부를래
// Link  : https://www.acmicpc.net/problem/34129 
// Time  : 188 ms
// Memory: 2548 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e5;

int nxt[kMax];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  vector<int> axr(n);
  iota(axr.begin(), axr.end(), 0);
  sort(axr.begin(), axr.end(), [&](int lhs, int rhs) {
    return arr[lhs] < arr[rhs];
  });

  bitset<kMax> memo;
  memo.set(0);
  int limit = 0;
  for (int i = 0; i < n - 1; i++) {
    int id = axr[i];
    auto mnxt = memo;
    mnxt |= (memo << arr[id]);
    limit = min<int>(limit + arr[id], k - 1);
    for (int j = 0; j <= limit; j++) {
      if (!memo[j] && mnxt[j]) {
        nxt[j] = id + 1;
      }
    }
    swap(memo, mnxt);
  }

  int maxx = limit;
  while (!memo[maxx]) --maxx;

  int64_t sum = arr[axr[n - 1]];
  vector<int> ans{axr[n - 1] + 1};
  while (maxx) {
    int mi = nxt[maxx];
    int cut = arr[mi - 1];
    maxx -= cut;
    sum += cut;
    ans.push_back(mi);
  }

  cout << ans.size() << " " << sum << "\n";
  for (auto e : views::reverse(ans)) cout << e << " ";

  return 0;
}
