// Title : 두 수의 합
// Link  : https://www.acmicpc.net/problem/9024 
// Time  : 400 ms
// Memory: 10360 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

bool Check(int x, int k) {
  int l = 0, r = arr.size() - 1;
  while (l < r) {
    if (abs(arr[l] + arr[r] - k) <= x) return true;
    if (arr[l] + arr[r] < k) {
      ++l;
    } else {
      --r;
    }
  }
  return false;
}

int Count(int x, int k) {
  int cnt = 0;
  int l = 0, r = arr.size() - 1;
  while (l < r) {
    while (l + 1 < r && arr[l] + arr[r] + x > k) --r;
    cnt += (arr[l++] + arr[r] + x == k);
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    arr.resize(n);
    for (auto& e : arr) cin >> e;
    sort(arr.begin(), arr.end());

    int lo = -1, hi = 3e8;
    while (lo + 1 < hi) {
      int mid = (lo + hi) >> 1;
      if (!Check(mid, k)) {
        lo = mid;
      } else {
        hi = mid;
      }
    }
    cout << Count(hi, k) + (hi != 0 ? Count(-hi, k) : 0) << "\n";
  }

  return 0;
}
