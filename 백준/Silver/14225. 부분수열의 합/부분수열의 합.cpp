#include <bits/stdc++.h>

using namespace std;

bool memo[2000001];
int arr[1 << 21];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int s = 1 << i;
    for (int j = 0; j < s; j++) {
      memo[arr[s + j] = arr[j] + x] = true;
    }
  }

  int ans = 1;
  while (memo[ans]) ans++;
  cout << ans;

  return 0;
}
