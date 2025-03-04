#include <bits/stdc++.h>

using namespace std;

bool memo[2000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int arr[20];
  for (int i = 0; i < n; i++) cin >> arr[i];
  queue<int> q;
  q.push(0);
  for (int i = 0; i < n; i++) {
    int nq = q.size();
    while (nq--) {
      int x = q.front();
      q.pop();
      memo[x] = true;
      q.push(x);
      q.push(x + arr[i]);
    }
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    memo[x] = true;
  }

  int ans = 1;
  while (memo[ans]) ++ans;
  cout << ans;

  return 0;
}
