#include <bits/stdc++.h>

using namespace std;

int m[1024][1024];

int Traverse(int y, int x, int n) {
  int arr[4];
  if (n == 2) {
    arr[0] = m[y][x];
    arr[1] = m[y][x + 1];
    arr[2] = m[y + 1][x];
    arr[3] = m[y + 1][x + 1];
  } else {
    int mid = n >> 1;
    arr[0] = Traverse(y, x, mid);
    arr[1] = Traverse(y, x + mid, mid);
    arr[2] = Traverse(y + mid, x, mid);
    arr[3] = Traverse(y + mid, x + mid, mid);
  }
  nth_element(arr, arr + 2, arr + 4);
  return arr[2];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> m[i][j];
    }
  }
  cout << Traverse(0, 0, n);

  return 0;
}
