// Title : 67
// Link  : https://www.acmicpc.net/problem/34908 
// Time  : 3672 ms
// Memory: 13808 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto Query = [&](int i, int j) {
    cout << "? " << i << " " << j << endl;
    int64_t x;
    cin >> x;
    return x;
  };

  auto GCD = [&](int64_t a, int64_t b) {
    while (b) a %= b, swap(a, b);
    return a;
  };

  vector<int> arr;

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    arr.resize(n);
    for (int i = 0; i + 3 <= n; i += 3) {
      int64_t ab = Query(i + 1, i + 2), ac = Query(i + 1, i + 3);
      int64_t a = GCD(ab, ac), b = ab / a, c = ac / a;
      arr[i] = a, arr[i + 1] = b, arr[i + 2] = c;
    }
    for (int i = (n / 3) * 3; i < n; i++) {
      arr[i] = Query(1, i + 1) / arr[0];
    }

    cout << "!";
    for (auto e : arr) cout << " " << e;
    cout << endl;
  }

  return 0;
}