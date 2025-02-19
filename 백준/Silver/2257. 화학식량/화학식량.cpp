#include <bits/stdc++.h>

using namespace std;

constexpr int kWeights[] = {0, 0, 12, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 16};

int Eval(string_view& sv) {
  int sum = 0, cur = 0;
  while (!sv.empty()) {
    char c = sv[0];
    sv = sv.substr(1);
    if (c == ')') break;
    if (c == '(') {
      sum += cur;
      cur = Eval(sv);
    } else if (c & 0x40) {
      sum += cur;
      cur = kWeights[c - 'A'];
    } else {
      sum += cur * (c - '0');
      cur = 0;
    }
  }
  return sum + cur;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  char str[101];
  cin >> str;
  string_view sv(str);
  cout << Eval(sv);

  return 0;
}
