// Title : 치터 잡기
// Link  : https://www.acmicpc.net/problem/33617
// Time  : 12 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

void Print1(int& y, int& x, int row, int mid, int n) {
  cout << n << " ";
  if (y == row) {
    for (int i = 2; i <= mid; i++) {
      cout << y << " " << i << " ";
    }
    ++y;
    for (int i = mid; i <= n; i++) {
      cout << y << " " << i << " ";
    }
    x = n;
  } else {
    for (int i = n - 1; i >= mid; i--) {
      cout << y << " " << i << " ";
    }
    --y;
    for (int i = mid; i >= 1; i--) {
      cout << y << " " << i << " ";
    }
    x = 1;
  }
  cout << "\n";
}

void Print2(int& y, int& x, int row, int mid, int n) {
  cout << n << " ";
  if (y == row) {
    for (int i = 2; i <= mid; i++) {
      cout << y << " " << n - i + 1 << " ";
    }
    ++y;
    for (int i = mid; i <= n; i++) {
      cout << y << " " << n - i + 1 << " ";
    }
    x = 1;
  } else {
    for (int i = n - 1; i >= mid; i--) {
      cout << y << " " << n - i + 1 << " ";
    }
    --y;
    for (int i = mid; i >= 1; i--) {
      cout << y << " " << n - i + 1 << " ";
    }
    x = n;
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, y = 1, x = 1;
  cin >> n;
  cout << (n - 1) * (n + (n % 2 == 0)) << "\n1 1\n";
  for (int i = 1; i < n; i++) {
    if (x == 1) {
      for (int j = n; j >= 1; j--) {
        Print1(y, x, i, j, n);
      }
    } else {
      for (int j = n; j >= 1; j--) {
        Print2(y, x, i, j, n);
      }
    }

    if (y == i) {
      cout << n << " ";
      if (x == 1) {
        for (int j = 1; j <= n; j++) {
          cout << y + 1 << " " << j << " ";
        }
      } else {
        for (int j = n; j >= 1; j--) {
          cout << y + 1 << " " << j << " ";
        }
      }
      cout << "\n";
      ++y, x = n - x + 1;
    }
  }

  return 0;
}
