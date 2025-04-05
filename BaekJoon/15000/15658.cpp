// Title : 연산자 끼워넣기 （2）
// Link  : https://www.acmicpc.net/problem/15658
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int n;
int arr[11];
int ops[4];
int minn = INT_MAX, maxx = INT_MIN;

void Traverse(int idx, int val) {
  if (idx == n) {
    if (minn > val) minn = val;
    if (maxx < val) maxx = val;
    return;
  }

  static const function<int(int, int)> kOps[] = {
      [](int a, int b) { return a + b; },
      [](int a, int b) { return a - b; },
      [](int a, int b) { return a * b; },
      [](int a, int b) { return a / b; }};

  for (int i = 0; i < 4; i++) {
    if (ops[i]) {
      --ops[i];
      Traverse(idx + 1, kOps[i](val, arr[idx]));
      ++ops[i];
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < 4; i++) cin >> ops[i];
  Traverse(1, arr[0]);
  cout << maxx << "\n" << minn;

  return 0;
}
