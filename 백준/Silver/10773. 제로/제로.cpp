#include <bits/stdc++.h>

using namespace std;

int nums[100000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  auto e = nums;
  while (n--) {
    int v;
    cin >> v;
    if (v) {
      *e++ = v;
    } else {
      --e;
    }
  }

  int sum = 0;
  auto it = nums;
  while (it != e) sum += *it++;
  cout << sum;

  return 0;
}
