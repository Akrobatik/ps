#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t m[4];
  for (auto& e : m) {
    int64_t a, b;
    cin >> a >> b;
    e = b - a;
  }

  cout << m[1] + m[2] + m[3] << "\n"
       << m[2] + m[3] << "\n"
       << m[3];

  return 0;
}
