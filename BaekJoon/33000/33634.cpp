// Title : 4교시: 국어 (Easy)
// Link  : https://www.acmicpc.net/problem/33634 
// Time  : 20 ms
// Memory: 3360 KB

#include <bits/stdc++.h>

using namespace std;

int ans;
vector<int> trr, arr, brr, crr;
bool visited[1000][11][11][11];

void Traverse(int a, int b, int c, int idx) {
  if (idx == trr.size()) {
    ans = max<int>(ans, a + b + c);
    return;
  }

  if (visited[idx][a][b][c]) return;
  visited[idx][a][b][c] = true;

  int t = trr[idx];
  auto ab = arr.begin() + a;
  auto ae = upper_bound(ab, arr.end(), arr[a] + t);
  for (auto ait = ae; ait != ab;) {
    int ad = *--ait - arr[a];
    auto bb = brr.begin() + b;
    auto be = upper_bound(bb, brr.end(), brr[b] + t - ad);
    int cmax = -1;
    for (auto bit = be; bit != bb;) {
      int bd = *--bit - brr[b];
      auto cb = crr.begin() + c;
      auto ce = upper_bound(cb, crr.end(), crr[c] + t - ad - bd);
      if (cb != ce && cmax < (ce - cb) - 1) {
        cmax = (ce - cb) - 1;
        auto cit = ce - 1;
        int cd = *cit - crr[c];
        Traverse(ait - arr.begin(), bit - brr.begin(), cit - crr.begin(), idx + 1);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, t;
  cin >> n >> t;
  trr.resize(n);
  for (auto& e : trr) cin >> e;
  for (int i = 1; i < n; i++) {
    trr[i - 1] = trr[i] - trr[i - 1] - 1;
  }
  trr.pop_back();

  int na, nb, nc;
  cin >> na >> nb >> nc;
  arr.resize(na + 1), brr.resize(nb + 1), crr.resize(nc + 1);
  for (int i = 1; i <= na; i++) cin >> arr[i];
  for (int i = 1; i <= nb; i++) cin >> brr[i];
  for (int i = 1; i <= nc; i++) cin >> crr[i];
  partial_sum(arr.begin(), arr.end(), arr.begin());
  partial_sum(brr.begin(), brr.end(), brr.begin());
  partial_sum(crr.begin(), crr.end(), crr.begin());

  Traverse(0, 0, 0, 0);
  cout << ans;

  return 0;
}
