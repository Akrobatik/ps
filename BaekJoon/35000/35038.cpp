// Title : 수 맞히기 게임
// Link  : https://www.acmicpc.net/problem/35038 
// Time  : 4 ms
// Memory: 2656 KB

#include "game.h"

int mj1000j(int n, int k) {
  if (k == 0) return 0;
  return ((1000 - n) / (2 * k)) & 1;
}

int anchor(int m, int k, int c) {
  if (k == 0) return m;
  int n = m - k;
  if (((1000 - n) / (2 * k) & 1) == c) return n;
  return m + k;
}