// Title : 나무 블록
// Link  : https://www.acmicpc.net/problem/4921 
// Time  : 4 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto Get = [&](char c) -> pair<int, int> {
    switch (c) {
      case '1':
        return {0, -1};
      case '2':
        return {-1, 0};
      case '3':
        return {-1, -1};
      case '4':
        return {1, 1};
      case '5':
        return {1, -2};
      case '6':
        return {-2, 1};
      case '7':
        return {-2, -2};
      case '8':
        return {2, 2};
    }
    assert(0);
  };

  string s;
  int t = 0;
  while (cin >> s && s != "0") {
    int cnt = count_if(s.begin(), s.end(), [](char c) { return c <= '2'; });
    bool ok = (cnt == 2 && s[0] == '1' && s.back() == '2');
    int cur = 0, n = s.size();
    for (int i = 0; ok && i < n; i++) {
      auto [l, r] = Get(s[i]);
      ok = (cur + l == 0);
      cur = r;
    }
    cout << ++t << (ok ? ". VALID\n" : ". NOT\n");
  }

  return 0;
}
