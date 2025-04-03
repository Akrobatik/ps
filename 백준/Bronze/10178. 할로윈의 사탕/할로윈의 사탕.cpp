#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (n--) {
    int64_t a, b;
    cin >> a >> b;
    cout << "You get " << a / b << " piece(s) and your dad gets " << a % b << " piece(s).\n";
  }

  return 0;
}
