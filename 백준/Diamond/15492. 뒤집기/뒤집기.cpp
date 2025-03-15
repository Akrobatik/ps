#include <bits/stdc++.h>

using namespace std;

int arr[8000000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int n2 = n << 1;
  for (int i = 1; i <= n; i++) cin >> arr[n - i], arr[n2 - i] = arr[n - i];

  int pos, i = 1;
  while (i < n) {
    pos = i;
    int k = i, j = i + 1;
    while (j < n2 && arr[j] >= arr[k]) {
      if (arr[j++] != arr[k++]) k = i;
    }
    i += (j - i) / (j - k) * (j - k);
  }

  if (i == n) {
    copy(arr + pos, arr + n - 1, arr + n);
    i = pos;
    while (i < n) {
      pos = i;
      int k = i, j = i + 1;
      while (j < n2 - 1 && arr[j] > arr[k]) {
        if (arr[j++] != arr[k++]) k = i;
      }
      i += (j - i) / (j - k) * (j - k);
    }
  }

  for (int i = pos; i < n; i++) {
    cout << arr[i] << " ";
  }
  for (int i = 0; i < pos; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}
