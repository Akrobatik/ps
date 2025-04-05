// Title : 덩치
// Link  : https://www.acmicpc.net/problem/7568
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

struct Man {
  bool operator<(const Man& rhs) const {
    return w < rhs.w && h < rhs.h;
  }

  int w, h;
};

Man mans[50];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> mans[i].w >> mans[i].h;
  }

  for (int i = 0; i < n; i++) {
    int cnt = 1;
    for (int j = 0; j < n; j++) {
      if (mans[i] < mans[j]) ++cnt;
    }
    cout << cnt << " ";
  }

  return 0;
}
