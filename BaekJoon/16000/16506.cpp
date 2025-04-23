// Title : CPU
// Link  : https://www.acmicpc.net/problem/16506 
// Time  : 0 ms
// Memory: 2032 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  unordered_map<string, bitset<4>> ops = {
      {"ADD", 0},
      {"SUB", 1},
      {"MOV", 2},
      {"AND", 3},
      {"OR", 4},
      {"NOT", 5},
      {"MULT", 6},
      {"LSFTL", 7},
      {"LSFTR", 8},
      {"ASFTR", 9},
      {"RL", 10},
      {"RR", 11},
  };

  int n;
  cin >> n;
  while (n--) {
    string a;
    int b, c, d;
    cin >> a >> b >> c >> d;

    if (a.back() == 'C') {
      a.pop_back();

      auto aa = ops[a];
      bitset<2> rc(2);
      bitset<3> bb(b);
      bitset<3> cc(c);
      bitset<4> dd(d);
      cout << aa << rc << bb << cc << dd << "\n";
    } else {
      auto aa = ops[a];
      bitset<2> rc(0);
      bitset<3> bb(b);
      bitset<3> cc(c);
      bitset<3> dd(d);
      cout << aa << rc << bb << cc << dd << "0\n";
    }
  }

  return 0;
}
