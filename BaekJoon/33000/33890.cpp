// Title : 양과 늑대
// Link  : https://www.acmicpc.net/problem/33890 
// Time  : 200 ms
// Memory: 5936 KB

#include <bits/stdc++.h>

using namespace std;

int Count(const vector<int>& arr, int k) {
  int cnt = 0, l = 0, r = arr.size() - 1;
  while (l < r) {
    if (arr[l] == 0) {
      ++l;
      continue;
    }
    if (arr[r] == 0) {
      --r;
      continue;
    }

    if (arr[l] + arr[r] <= k) {
      ++cnt;
      ++l, --r;
    } else {
      --r;
    }
  }
  return cnt;
}

int Find(vector<int>& arr, int k, int maxx) {
  int n = arr.size();
  int lo = 0, hi = n - 1, p = n;
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    int x = arr[mid];
    arr[mid] = 0;
    if (Count(arr, k) < maxx) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
      p = min<int>(p, mid);
    }
    arr[mid] = x;
  }
  return p != n ? arr[p] : k;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;
  vector<int> arr(n), brr(m);
  for (auto& e : arr) cin >> e;
  for (auto& e : brr) cin >> e;
  sort(arr.begin(), arr.end());
  sort(brr.begin(), brr.end());

  int maxa = Count(arr, k), maxb = Count(brr, k);
  int mina = Find(arr, k, maxa), minb = Find(brr, k, maxb);
  cout << n + m - maxa - maxb - (mina + minb <= k);

  return 0;
}
