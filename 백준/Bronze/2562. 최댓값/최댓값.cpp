#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int idx;
  int maxx = INT_MIN;
  for (int i = 1; i <= 9; i++) {
    int v;
    cin >> v;
    if (maxx < v) maxx = v, idx = i;
  }
  cout << maxx << "\n"
       << idx;

  return 0;
}
