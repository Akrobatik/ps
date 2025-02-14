#include <bits/stdc++.h>

using namespace std;

int nums[10001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (n--) {
    int v;
    cin >> v;
    ++nums[v];
  }

  for (int i = 1; i <= 10000; i++) {
    while (nums[i]--) cout << i << "\n";
  }

  return 0;
}
