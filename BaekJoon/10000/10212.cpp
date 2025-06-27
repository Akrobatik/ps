// Title : Mystery
// Link  : https://www.acmicpc.net/problem/10212 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr const char* kStr[2] = {
    "Yonsei",
    "Korea",
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  mt19937 gen(random_device{}());
  cout << kStr[gen() & 1];

  return 0;
}
