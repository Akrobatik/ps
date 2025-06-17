// Title : 우리의 다정한 계절 속에(Seasons of Memories)
// Link  : https://www.acmicpc.net/problem/34028 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int yy, mm, dd;
  cin >> yy >> mm >> dd;

  int cnt = 0;
  if (yy > 2016) {
    int cut = yy - 2016;
    yy -= cut;
    cnt += cut * 4;
  }

  int mmdd = mm * 100 + dd;
  if (yy == 2015) {
    if (116 <= mmdd && mmdd < 301) {
      cnt += 1;
    } else if (301 <= mmdd && mmdd < 601) {
      cnt += 2;
    } else if (601 <= mmdd && mmdd < 901) {
      cnt += 3;
    } else if (901 <= mmdd && mmdd < 1201) {
      cnt += 4;
    } else if (1201 <= mmdd) {
      cnt += 5;
    }
  } else if (yy == 2016) {
    if (mmdd < 301) {
      cnt += 5;
    } else if (301 <= mmdd && mmdd < 601) {
      cnt += 6;
    } else if (601 <= mmdd && mmdd < 901) {
      cnt += 7;
    } else if (901 <= mmdd && mmdd < 1201) {
      cnt += 8;
    } else if (1201 <= mmdd) {
      cnt += 9;
    }
  }

  cout << cnt;

  return 0;
}
