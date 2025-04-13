// Title : 잘못된 버블정렬
// Link  : https://www.acmicpc.net/problem/30010 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

bool Test(int N, vector<int> A) {
  for (int i = N - 1; i > 0; i--) {
    for (int j = i - 1; j >= 0; j--) {
      if (A[j] > A[j + 1]) {
        int tmp = A[j];
        A[j] = A[j + 1];
        A[j + 1] = tmp;
      }
    }
  }

  for (int i = 1; i < N; i++) {
    if (A[i - 1] > A[i]) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  cout << n;
  for (int i = 1; i < n; i++) {
    cout << " " << i;
  }

  return 0;
}
