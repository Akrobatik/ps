// Title : 내 뒤에 나와 다른 수
// Link  : https://www.acmicpc.net/problem/24523 
// Time  : 208 ms
// Memory: 5928 KB

#include <bits/stdc++.h>

using namespace std;

int arr[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i];

  int idx = 1;
  while (idx <= n) {
    int nxt = idx + 1;
    while (nxt <= n && arr[idx] == arr[nxt]) ++nxt;
    int x = nxt == n + 1 ? -1 : nxt;
    for (int i = idx; i < nxt; i++) {
      cout << x << " ";
    }
    idx = nxt;
  }

  return 0;
}
