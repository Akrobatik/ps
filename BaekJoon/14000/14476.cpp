// Title : 최대공약수 하나 빼기
// Link  : https://www.acmicpc.net/problem/14476 
// Time  : 156 ms
// Memory: 13744 KB

#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b) {
  while (b) a %= b, swap(a, b);
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) cin >> arr[i];

  vector<int> fwd(n + 2);
  for (int i = 1; i <= n; i++) fwd[i] = GCD(fwd[i - 1], arr[i]);

  vector<int> bwd(n + 2);
  for (int i = n; i >= 1; i--) bwd[i] = GCD(bwd[i + 1], arr[i]);

  int maxx = 0, mi;
  for (int i = 1; i <= n; i++) {
    int g = GCD(fwd[i - 1], bwd[i + 1]);
    if (maxx < g) maxx = g, mi = i;
  }

  if (fwd[n] == maxx) {
    cout << "-1";
  } else {
    cout << maxx << " " << arr[mi];
  }

  return 0;
}