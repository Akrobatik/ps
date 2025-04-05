// Title : 현실적인 생일 축하 방안
// Link  : https://www.acmicpc.net/problem/33664
// Time  : 0 ms
// Memory: 2292 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t b, n, m;
  cin >> b >> n >> m;
  unordered_map<string, int64_t> hm;
  while (n--) {
    string s;
    int64_t x;
    cin >> s >> x;
    hm[s] = x;
  }
  int64_t sum = 0;
  while (m--) {
    string s;
    cin >> s;
    sum += hm[s];
  }
  cout << (sum <= b ? "acceptable" : "unacceptable");

  return 0;
}
