// Title : 알고리즘 수업 - 병합 정렬 1
// Link  : https://www.acmicpc.net/problem/24060 
// Time  : 184 ms
// Memory: 104360 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
int arr[500001], tmp[500001];

void Merge(int* a, int p, int q, int r) {
  int i = p, j = q + 1, t = 1;
  while (i <= q && j <= r) {
    if (a[i] <= a[j]) {
      tmp[t++] = a[i++];
    } else {
      tmp[t++] = a[j++];
    }
  }

  while (i <= q) tmp[t++] = arr[i++];
  while (j <= r) tmp[t++] = arr[j++];

  i = p, t = 1;
  while (i <= r) {
    a[i] = tmp[t++];
    ans.push_back(a[i++]);
  }
}

void MergeSort(int* a, int p, int r) {
  if (p < r) {
    int q = (p + r) >> 1;
    MergeSort(a, p, q);
    MergeSort(a, q + 1, r);
    Merge(a, p, q, r);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= n; i++) cin >> arr[i];
  MergeSort(arr, 1, n);

  cout << (ans.size() < k ? -1 : ans[k - 1]);

  return 0;
}
