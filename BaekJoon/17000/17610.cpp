// Title : 양팔저울
// Link  : https://www.acmicpc.net/problem/17610 
// Time  : 8 ms
// Memory: 4560 KB

#include <bits/stdc++.h>

using namespace std;

int arr[13];
bool memo[2600001];

void Traverse(int i, int e, int sum) {
  if (i == e) {
    memo[abs(sum)] = true;
    return;
  }

  Traverse(i + 1, e, sum);
  Traverse(i + 1, e, sum + arr[i]);
  Traverse(i + 1, e, sum - arr[i]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i], sum += arr[i];

  Traverse(0, n, 0);
  int cnt = sum;
  for (int i = 1; i <= sum; i++) {
    cnt -= memo[i];
  }
  cout << cnt;

  return 0;
}
