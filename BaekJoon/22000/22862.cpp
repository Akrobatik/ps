// Title : 가장 긴 짝수 연속한 부분 수열 (large)
// Link  : https://www.acmicpc.net/problem/22862 
// Time  : 96 ms
// Memory: 5220 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> arr;
  int pb = 0, cnt = 0;
  while (n--) {
    int x;
    cin >> x;
    if ((x & 1) == pb) {
      ++cnt;
    } else {
      arr.push_back(cnt);
      pb ^= 1, cnt = 1;
    }
  }

  int na = arr.size();
  if (!(na & 1)) arr.push_back(cnt), ++na;

  int maxx = 0, r = -1, odd = 0, even = arr[0];
  for (int i = 0; i < na; i += 2) {
    while (r + 2 < na && odd + arr[r + 2] <= k) {
      odd += arr[r + 2];
      even += arr[r + 3];
      r += 2;
    }
    maxx = max<int>(maxx, even);
    if (i <= r) even -= arr[i], odd -= arr[i + 1];
  }
  cout << maxx;

  return 0;
}
