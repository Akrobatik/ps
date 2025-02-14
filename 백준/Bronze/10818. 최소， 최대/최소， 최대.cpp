#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int minn = INT_MAX, maxx = INT_MIN;
  while (n--) {
    int v;
    cin >> v;
    if (minn > v) minn = v;
    if (maxx < v) maxx = v;
  }
  cout << minn << " " << maxx;

  return 0;
}
