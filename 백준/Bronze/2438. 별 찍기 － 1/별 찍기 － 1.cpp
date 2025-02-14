#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      cout << "*";
    }
    cout <<"\n";
  }

  return 0;
}
