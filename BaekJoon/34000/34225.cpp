// Title : 현대모비스 부품 조립
// Link  : https://www.acmicpc.net/problem/34225 
// Time  : 60 ms
// Memory: 3592 KB

#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);

  cin.tie(nullptr);

  int n;

  cin >> n;

  vector<int> arr(n + 1);

  for (int i = 1; i <= n; i++) cin >> arr[i];

  vector<int> ids(n);

  iota(ids.begin(), ids.end(), 1);

  sort(ids.begin(), ids.end(), [&](int lhs, int rhs) {

    return arr[lhs] > arr[rhs];

  });

  int64_t maxx = 0, sum = arr[ids[0]], mi;

  for (int i = 0; i < n; i++) {

    int64_t val = arr[ids[i]];

    sum += val;

    int64_t cur = sum + val;

    if (maxx < cur) maxx = cur, mi = i;

  }

  cout << mi + 1 << "\n";

  for (int i = 0; i <= mi; i++) cout << ids[i] << " ";

  return 0;

}

