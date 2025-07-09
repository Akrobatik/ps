// Title : 연산자 끼워넣기
// Link  : https://www.acmicpc.net/problem/14888 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int arr[11], ops[10], cnt[4];
int minn, maxx;

void Traverse(int idx, int limit) {
  if (idx == limit) {
    int cur = arr[0];
    for (int i = 0; i < limit; i++) {
      switch (ops[i]) {
        case 0: {
          cur += arr[i + 1];
        } break;
        case 1: {
          cur -= arr[i + 1];
        } break;
        case 2: {
          cur *= arr[i + 1];
        } break;
        case 3: {
          cur /= arr[i + 1];
        } break;
      }
    }
    minn = min<int>(minn, cur);
    maxx = max<int>(maxx, cur);
    return;
  }

  for (int i = 0; i < 4; i++) {
    if (cnt[i] == 0) continue;
    --cnt[i];
    ops[idx] = i;
    Traverse(idx + 1, limit);
    ++cnt[i];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < 4; i++) cin >> cnt[i];

  minn = INT_MAX, maxx = INT_MIN;
  Traverse(0, n - 1);
  cout << maxx << "\n"
       << minn;

  return 0;
}
