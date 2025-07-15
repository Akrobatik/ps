// Title : 대기업 승범이네
// Link  : https://www.acmicpc.net/problem/17831 
// Time  : 88 ms
// Memory: 26196 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> edges[200001];
int arr[200001];

pair<int64_t, int64_t> Traverse(int cur) {
  int64_t imax = 0, emax = 0;
  for (auto nxt : edges[cur]) {
    auto [im, em] = Traverse(nxt);
    imax = max<int64_t>(imax, em - im + arr[cur] * arr[nxt]);
    emax += im;
  }
  return {emax + imax, emax};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    edges[x].push_back(i);
  }

  for (int i = 1; i <= n; i++) cin >> arr[i];

  auto [imax, emax] = Traverse(1);
  cout << max<int64_t>(imax, emax);

  return 0;
}
