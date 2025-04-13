// Title : 정수 a를 k로 만들기
// Link  : https://www.acmicpc.net/problem/25418 
// Time  : 0 ms
// Memory: 2996 KB

#include <bits/stdc++.h>

using namespace std;

bool visited[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, k;
  cin >> a >> k;

  int cnt = 0;
  while (a != k) {
    ++cnt;
    if (!(k & 1) && a <= (k >> 1)) {
      k >>= 1;
    } else {
      --k;
    }
  }
  cout << cnt;

  return 0;
}
