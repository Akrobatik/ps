// Title : 거짓말쟁이 2
// Link  : https://www.acmicpc.net/problem/35058 
// Time  : 16 ms
// Memory: 3560 KB

#include "liar.h"
//
#include <bits/stdc++.h>

using namespace std;

int shout(int N, int a, int b, std::vector<int> S, int l, int r) {
  return (a == 1 ? r : l ^ r);
}

int answer(int N, int a, int b, std::vector<int> T, int l, int r) {
  if (a & 1) {
    int key = 0;
    for (auto e : T) key ^= e;
    for (int i = N - 2; i >= a; i -= 2) {
      key ^= T[i];
    }
    if (a == 1) key ^= T[0] ^ r;
    return key;
  } else {
    int key = T[0];
    for (int i = 2; i < a; i += 2) {
      key ^= T[i];
    }
    return key;
  }
}