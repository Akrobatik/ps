// Title : 겨울 축제 2
// Link  : https://www.acmicpc.net/problem/35060 
// Time  : 8 ms
// Memory: 2160 KB

#include "festival.h"
//
#include <bits/stdc++.h>

int answer(int N, int K, int i, std::vector<int> v) {
  int64_t acc = 0;
  for (auto e : v) acc += e;
  return K - acc % K;
}
