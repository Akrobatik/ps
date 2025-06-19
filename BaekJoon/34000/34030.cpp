// Title : So☆Lucky
// Link  : https://www.acmicpc.net/problem/34030 
// Time  : 32 ms
// Memory: 4980 KB

#include <bits/stdc++.h>

using namespace std;

bool Check(const vector<int>& arr) {
  int n = arr.size();
  for (int i = 1; i < n; i++) {
    if (arr[i - 1] > arr[i]) return false;
  }
  return true;
}

bool Solve1(const vector<int>& arr) {
  vector<int> odd, even;
  for (auto e : arr) {
    if (e & 1) {
      odd.push_back(e);
    } else {
      even.push_back(e);
    }
  }
  return Check(odd) && Check(even);
}

bool Solve2(const vector<int>& arr) {
  vector<int> brr;
  int n = arr.size(), idx = 0;
  while (idx < n) {
    int parity = arr[idx] & 1;
    int minn = INT_MAX, maxx = INT_MIN;
    while (idx < n && parity == (arr[idx] & 1)) {
      minn = min<int>(minn, arr[idx]);
      maxx = max<int>(maxx, arr[idx]);
      ++idx;
    }
    brr.push_back(minn);
    brr.push_back(maxx);
  }
  return Check(brr);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  cout << (Solve1(arr) ? "So Lucky\n" : "Unlucky\n")
       << (Solve2(arr) ? "So Lucky\n" : "Unlucky\n");

  return 0;
}
