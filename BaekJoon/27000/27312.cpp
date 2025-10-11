// Title : 운영진에게 설정 짜기는 어려워
// Link  : https://www.acmicpc.net/problem/27312 
// Time  : 60 ms
// Memory: 36952 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m, n, q;
  cin >> m >> n >> q;
  vector<int> arr(n), ans(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    ans[i] = arr[i];
  }

  for (int i = 0; i < q; i++) {
    cout << "? " << (i % m) + 1 << " " << i + 1 << endl;
    int x;
    cin >> x;
    ans[i] = (x < arr[i] ? x + 1 : 1);
  }

  cout << "!";
  for (auto e : ans) cout << " " << e;
  cout << endl;

  return 0;
}