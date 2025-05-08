// Title : 세 수의 합
// Link  : https://www.acmicpc.net/problem/2295 
// Time  : 8 ms
// Memory: 5936 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kShift = 15;
constexpr int kMask = (1 << kShift) - 1;

void SortG(int* arr, int n) {
  int tmp[1000];
  auto a = arr, b = tmp;
  for (int shift = 0; shift != 30; shift += kShift) {
    int cnt[kMask + 1] = {};
    for (int i = 0; i < n; i++) ++cnt[(a[i] >> shift) & kMask];
    for (int i = kMask; i; i--) cnt[i - 1] += cnt[i];
    int idx = n;
    while (idx--) b[--cnt[(a[idx] >> shift) & kMask]] = a[idx];
    swap(a, b);
  }
}

void SortL(int* arr, int n) {
  int tmp[500500];
  auto a = arr, b = tmp;
  for (int shift = 0; shift != 30; shift += kShift) {
    int cnt[kMask + 1] = {};
    for (int i = 0; i < n; i++) ++cnt[(a[i] >> shift) & kMask];
    for (int i = 1; i <= kMask; i++) cnt[i] += cnt[i - 1];
    int idx = n;
    while (idx--) b[--cnt[(a[idx] >> shift) & kMask]] = a[idx];
    swap(a, b);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  SortG(arr.data(), n);

  vector<int> brr;
  brr.reserve(n * (n + 1) / 2);
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      brr.push_back(arr[i] + arr[j]);
    }
  }
  SortL(brr.data(), brr.size());

  for (int i = 0; i < n; i++) {
    int k = 0;
    for (int j = i + 1; j < n; j++) {
      int x = arr[i] - arr[j];
      while (k < brr.size() && brr[k] < x) ++k;
      if (k == brr.size()) break;
      if (brr[k] == x) {
        cout << arr[i];
        return 0;
      }
    }
  }

  return 0;
}