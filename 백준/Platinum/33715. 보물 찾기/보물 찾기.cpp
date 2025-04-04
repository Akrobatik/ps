#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

pair<int, int> Find() {
  int l = 0, n = arr.size();
  while (l + 1 < n && arr[l] != arr[l + 1]) ++l;
  int r = l, x = arr[l];
  while (r + 1 < n && arr[r + 1] == x) ++r;
  return {l + 2, r + 2};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  arr.resize(n - 2);
  for (int i = 2; i <= n - 1; i++) {
    cout << i << " " << i << endl;
    cin >> arr[i - 2];
    if (arr[i - 2] == -1) return 0;
  }

  auto [l, r] = Find();
  cout << l << " " << r << endl;
  int x;
  cin >> x;
  if (x == -1) return 0;
  cout << r << " " << l << endl;
  cin >> x;

  return 0;
}
