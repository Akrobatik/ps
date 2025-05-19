// Title : Was It a Cat I Saw
// Link  : https://www.acmicpc.net/problem/33887 
// Time  : 4 ms
// Memory: 2536 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> memo;
array<int, 15> arr;

void Traverse(int idx) {
  bitset<32> bits;
  int len = idx << 1;
  for (int i = 0; i < idx; i++) {
    if (arr[i]) bits.set(i), bits.set(len - i - 1);
  }
  memo.push_back(bits.to_ulong());

  bits = 0;
  --len;
  for (int i = 0; i < idx; i++) {
    if (arr[i]) bits.set(i), bits.set(len - i - 1);
  }
  memo.push_back(bits.to_ulong());

  if (idx == 15) return;

  arr[idx] = 0;
  Traverse(idx + 1);
  arr[idx] = 1;
  Traverse(idx + 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  arr[0] = 1;
  Traverse(1);
  memo.push_back(0);
  sort(memo.begin(), memo.end());

  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    auto it = lower_bound(memo.begin(), memo.end(), x);
    int ans = abs(*it - x);
    ans = min<int>(ans, abs(*--it - x));
    cout << ans << "\n";
  }

  return 0;
}
