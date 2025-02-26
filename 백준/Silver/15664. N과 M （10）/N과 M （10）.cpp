#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) cin >> nums[i];

  vector<int8_t> perm(n);
  fill(perm.end() - m, perm.end(), 1);

  set<vector<int>> st;
  do {
    vector<int> arr;
    arr.reserve(m);
    for (int i = 0; i < n; i++) {
      if (!perm[i]) continue;
      arr.push_back(nums[i]);
    }
    sort(arr.begin(), arr.end());
    st.insert(arr);
  } while (next_permutation(perm.begin(), perm.end()));

  for (auto& arr : st) {
    string s;
    for (auto e : arr) {
      s.append(to_string(e)).push_back(' ');
    }
    s.back() = '\n';
    cout << s;
  }

  return 0;
}
