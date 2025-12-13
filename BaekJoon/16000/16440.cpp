// Title : 제이크와 케이크
// Link  : https://www.acmicpc.net/problem/16440 
// Time  : 0 ms
// Memory: 2648 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;

  int half = n >> 1, quad = n >> 2, cnt = 0;
  for (int i = 0; i < half; i++) {
    cnt += (s[i] == 's');
  }

  if (cnt == quad) {
    cout << "1\n"
         << half;
    return 0;
  }

  for (int i = 0; i < half; i++) {
    cnt += (s[i + half] == 's') - (s[i] == 's');
    if (cnt == quad) {
      cout << "2\n"
           << i + 1 << " " << i + half + 1;
      return 0;
    }
  }

  return 0;
}