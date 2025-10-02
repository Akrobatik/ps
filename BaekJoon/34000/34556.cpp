// Title : MBTI 소개팅
// Link  : https://www.acmicpc.net/problem/34556 
// Time  : 108 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  auto Read = []() {
    string s;
    cin >> s;
    constexpr char kTable[] = "ISTP";
    int x = 0;
    for (int i = 0; i < 4; i++) {
      if (s[i] == kTable[i]) x |= (1 << i);
    }
    return x;
  };

  vector<int> arr(n), brr(n);
  for (auto& e : arr) e = Read();
  for (auto& e : brr) e = Read();

  vector<int> perm(n);
  iota(perm.begin(), perm.end(), 0);

  int maxx = 0;
  do {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int key = arr[i] ^ brr[perm[i]];
      sum += popcount((uint32_t)key);
    }
    maxx = max<int>(maxx, sum);
  } while (next_permutation(perm.begin(), perm.end()));
  cout << maxx;

  return 0;
}