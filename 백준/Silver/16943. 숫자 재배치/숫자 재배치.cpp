#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b;
  cin >> a >> b;
  vector<int> aa;
  while (a) aa.push_back(a % 10), a /= 10;
  sort(aa.begin(), aa.end());

  int maxx = 0;
  do {
    if (aa[0] == 0) continue;
    int c = 0;
    for (auto e : aa) c = c * 10 + e;
    if (b > c && maxx < c) maxx = c;
  } while (next_permutation(aa.begin(), aa.end()));

  cout << (maxx ? maxx : -1);

  return 0;
}
