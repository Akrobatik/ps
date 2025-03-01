#include <bits/stdc++.h>

using namespace std;

int ans = -1;
int n, s, m;
bool memo[50][1001];
int arr[50];

void Traverse(int idx, int cur) {
  if (idx == n) {
    if (ans < cur) ans = cur;
    return;
  }

  for (auto e : {cur - arr[idx], cur + arr[idx]}) {
    if (0 <= e && e <= m && !memo[idx][e]) {
      memo[idx][e] = true;
      Traverse(idx + 1, e);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> s >> m;
  for (int i = 0; i < n; i++) cin >> arr[i];
  Traverse(0, s);
  cout << ans;

  return 0;
}
