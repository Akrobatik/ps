#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> items;
  items.resize(n);
  for (int i = 0; i < n; i++) cin >> items[i];
  sort(items.begin(), items.end());
  auto b = items.begin();
  auto e = items.end() - 1;
  int minn = INT_MAX;
  int ans[2];

  while (b != e) {
    int sum = *b + *e;
    int sum_abs = abs(sum);
    if (minn > sum_abs) {
      minn = sum_abs;
      ans[0] = *b;
      ans[1] = *e;
      if (sum_abs == 0) break;
    }

    if (sum > 0) {
      e--;
    } else {
      b++;
    }
  }

  cout << ans[0] << " " << ans[1] << endl;

  return 0;
}
