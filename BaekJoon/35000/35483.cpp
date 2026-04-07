// Title : 루미상관 수
// Link  : https://www.acmicpc.net/problem/35483 
// Time  : 0 ms
// Memory: 2004 KB

#include <stdio.h>

#include <vector>

using namespace std;

int main() {
  vector<int> arr;

  auto F1 = [&](int st, int en, int mul) {
    for (int i = st, iv = st * mul; i < en; i++, iv += mul) {
      arr.push_back(iv);
    }
  };

  auto F2 = [&](int st, int en, int mul) {
    int imul = mul, jmul = mul / 10;
    for (int i = st, iv = st * imul; i < en; i++, iv += imul) {
      for (int j = 0, jv = 0; j < 10; j++, jv += jmul) {
        arr.push_back(iv + jv);
      }
    }
  };

  F1(1, 10, 1);
  F1(1, 10, 11);
  F2(1, 10, 101);
  F1(10, 100, 101);
  F2(10, 100, 1001);
  F1(100, 1000, 1001);
  F2(100, 1000, 10001);
  F1(1000, 10000, 10001);
  F2(1000, 10000, 100001);

  int t;
  scanf("%d\n", &t);
  while (t--) {
    int n;
    scanf("%d\n", &n);

    int cnt = 0, l = 0, r = arr.size() - 1;
    while (l <= r) {
      int sum = arr[l] + arr[r];
      if (sum < n) {
        ++l;
      } else if (sum > n) {
        --r;
      } else {
        cnt += (l == r ? 1 : 2);
        ++l, --r;
      }
    }
    printf("%d\n", cnt);
  }

  return 0;
}