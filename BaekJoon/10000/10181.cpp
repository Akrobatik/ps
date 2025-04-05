// Title : Federation Favorites
// Link  : https://www.acmicpc.net/problem/10181
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> elems;
  int n;
  while (cin >> n && n != -1) {
    elems.clear();
    int half = n >> 1;
    int64_t sum = 1;
    for (int i = 2; i <= half; i++) {
      if (n % i == 0) elems.push_back(i), sum += i;
    }
    if (sum == n) {
      cout << n << " = 1";
      for (auto e : elems) cout << " + " << e;
      cout << "\n";
    } else {
      cout << n << " is NOT perfect.\n";
    }
  }

  return 0;
}
