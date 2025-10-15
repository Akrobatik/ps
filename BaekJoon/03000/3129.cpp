// Title : 상범이의 은밀한 메세지
// Link  : https://www.acmicpc.net/problem/3129 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

struct ZAlgorithm {
  void Init(span<int> sv) {
    int n = sv.size();
    z.clear(), z.resize(n, 0);

    int rem = 0, cnt;
    for (int i = 1; i < n; i++) {
      auto& x = z[i];
      if (rem) x = min<int>(rem--, z[++cnt]);
      while (i + x < n && sv[i + x] == sv[x]) ++x;
      if (rem < x - 1) rem = x - 1, cnt = 0;
    }
    z[0] = n;
  }

  vector<int> z;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s1, s2;
  cin >> s1 >> s2;

  ZAlgorithm z;

  int n1 = s1.size(), n2 = s2.size();
  int half = n2 >> 1;
  vector<int> arr(n2);
  for (int i = 0; i + n2 <= n1; i++) {
    for (int j = 0; j < n2; j++) {
      arr[j] = (s1[i + j] - s2[j] + 26) % 26;
    }
    z.Init(arr);

    int nk = 0;
    for (int j = 1; j <= half; j++) {
      bool ok = true;
      for (int k = j; ok && k < n2; k += j) {
        ok = (z.z[k] + k == n2);
      }
      if (ok) {
        nk = j;
        break;
      }
    }
    if (nk == 0) continue;

    for (int j = 0; j < n1; j++) {
      int d = (j - i) % nk;
      if (d < 0) d += nk;
      cout << (char)((s1[j] - 'a' - arr[d] + 26) % 26 + 'a');
    }
  }

  return 0;
}