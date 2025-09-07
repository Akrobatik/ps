// Title : 하노이 여행하기
// Link  : https://www.acmicpc.net/problem/34223 
// Time  : 16 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);

  cin.tie(nullptr);

  int t;

  cin >> t;

  while (t--) {

    int n;

    cin >> n;

    if (n <= 4) {

      for (int i = 1; i <= n; i++) {

        cout << i % n + 1 << " ";

      }

      cout << "\n";

      cout << "1 2\n";

      continue;

    }

    if (n == 6) {

      cout << "2 3 1 5 4 4\n";

      cout << "1 6\n";

      continue;

    }

    if (n & 1) {

      int l = n >> 1, r = n - l;

      for (int i = 1; i <= l; i++) {

        cout << i % l + 1 << " ";

      }

      for (int i = 1; i <= r; i++) {

        cout << i % r + l + 1 << " ";

      }

      cout << "\n";

      cout << "1 " << l + 1 << "\n";

      continue;

    }

    int half = n >> 1;

    int l = half - 1, r = half + 1;

    if (~l & 1) --l, ++r;

    for (int i = 1; i <= l; i++) {

      cout << i % l + 1 << " ";

    }

    for (int i = 1; i <= r; i++) {

      cout << i % r + l + 1 << " ";

    }

    cout << "\n";

    cout << "1 " << l + 1 << "\n";

  }

  return 0;

}

