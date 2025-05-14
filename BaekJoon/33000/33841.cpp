// Title : 괄호 뒤집기
// Link  : https://www.acmicpc.net/problem/33841 
// Time  : 8 ms
// Memory: 5512 KB

#include <bits/stdc++.h>

using namespace std;

void Solve() {
  int n;
  string s;
  cin >> n >> s;
  int half = n;
  n <<= 1;

  vector<int> arr(n + 1);
  for (int i = 0; i < n; i++) {
    arr[i + 1] = arr[i] + (s[i] == '(' ? 1 : -1);
  }

  bool ok = true;
  for (int i = 0; ok && i < n; i++) {
    ok = (arr[i + 1] >= 0);
  }
  if (ok) {
    cout << "0\n";
    return;
  }

  int maxx = INT_MIN, maxp;
  for (int i = 0; i <= n; i++) {
    if (maxx < arr[i]) maxx = arr[i], maxp = i;
  }

  int l = 0, r = n;
  while (arr[l] >= 0) ++l;
  while (arr[r] >= 0) --r;

  int bl = 0, br = r;
  for (int i = 0; i < l; i++) {
    if (arr[bl] < arr[i]) bl = i;
  }
  for (int i = r; i <= n; i++) {
    if (arr[br] < arr[i]) br = i;
  }

  if (arr[bl] + arr[br] >= maxx) {
    cout << "1\n"
         << bl + 1 << " " << br << "\n";
  } else {
    cout << "2\n"
         << "1 " << maxp << "\n"
         << maxp + 1 << " " << n << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) Solve();

  return 0;
}