// Title : 순열 복원
// Link  : https://www.acmicpc.net/problem/32861 
// Time  : 64 ms
// Memory: 5928 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n, n);
  vector<int> mat(n * n);
  vector<bool> check(n + 1);

  for (auto& e : mat) cin >> e;

  for (int i = 0; i < n * n; i++) {
    int y = i / n, x = i % n;
    if (x == y) {
      if (mat[i] != 0) {
        cout << "-1";
        return 0;
      }
    } else {
      int a = mat[y * n + x], b = mat[x * n + y];
      if (a == 0 || b == 0 || a + b != 0) {
        cout << "-1";
        return 0;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    auto& x = arr[i];
    for (int j = 0; j < n; j++) {
      if (mat[i * n + j] == 1) --x;
    }
    if (check[x]) {
      cout << "-1";
      return 0;
    }
    check[x] = true;
  }

  for (auto e : arr) cout << e << " ";

  return 0;
}
