// Title : Secret
// Link  : https://www.acmicpc.net/problem/13220 
// Time  : 28 ms
// Memory: 3588 KB

#include <bits/stdc++.h>

using namespace std;

int Rotate(const vector<int>& arr) {
  int n = arr.size(), half = n >> 1;
  int res, i = 0;
  while (i < half) {
    res = i;
    int j = i + 1, k = i;
    while (j < n && arr[j] >= arr[k]) {
      if (arr[j++] != arr[k++]) k = i;
    }
    i += (j - i) / (j - k) * (j - k);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n << 1), brr(n << 1);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    arr[i + n] = arr[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> brr[i];
    brr[i + n] = brr[i];
  }

  int ai = Rotate(arr), bi = Rotate(brr);
  bool ok = true;
  for (int i = 0; ok && i < n; i++) {
    ok = (arr[ai + i] == brr[bi + i]);
  }
  cout << (ok ? "YES" : "NO");

  return 0;
}
