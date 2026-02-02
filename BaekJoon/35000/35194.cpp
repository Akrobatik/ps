// Title : Calculation Obfuscation
// Link  : https://www.acmicpc.net/problem/35194 
// Time  : 16 ms
// Memory: 11548 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int cnt[256] = {};
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    ++cnt[c];
  }

  if (cnt['('] != cnt[')']) {
    cout << "impossible";
    return 0;
  }

  int add = cnt['+'], mul = cnt['*'], brk = cnt['('];
  if (min<int>(add, mul * 2) < brk) {
    cout << "impossible";
    return 0;
  }

  int zr = cnt['0'], nz = n - (add + mul + brk * 2 + zr);
  int bnd = add + mul + 1;
  if (zr + nz < bnd || (nz == 0 && zr != bnd)) {
    cout << "impossible";
    return 0;
  }

  int oidx = 0;
  vector<int> ord;
  for (int i = 'a'; i <= 'z'; i++) {
    ord.push_back(i);
  }
  for (int i = '9'; i >= '0'; i--) {
    ord.push_back(i);
  }

  auto One = [&]() -> char {
    while (cnt[ord[oidx]] == 0) ++oidx;
    --cnt[ord[oidx]];
    return ord[oidx];
  };

  auto All = [&](string& s) {
    int no = ord.size();
    for (;;) {
      while (oidx < no && cnt[ord[oidx]] == 0) ++oidx;
      if (oidx == no) break;
      --cnt[ord[oidx]];
      s.push_back(ord[oidx]);
    }
  };

  vector<string> base(bnd);
  base[bnd - 1].push_back(One());
  for (int i = 0; i + 1 < bnd; i++) {
    base[i].push_back(One());
  }
  All(base[bnd - 1]);

  int cut = brk * 2 - bnd;
  if (cut > 0) {
    base[0] = string(cut + 1, '(') + base[0] + '+' + base.back() + ')';
    for (int i = 0; i < cut; i++) {
      string s1, s2, s3;
      s1 = base.back(), base.pop_back();
      s2 = base.back(), base.pop_back();
      s3 = base.back(), base.pop_back();
      base[0].push_back('*');
      base[0].push_back('(');
      base[0].append(s1);
      base[0].push_back('+');
      base[0].append(s2);
      base[0].push_back(')');
      base[0].push_back('+');
      base[0].append(s3);
      base[0].push_back(')');
    }
    brk -= cut * 2, mul -= cut, bnd -= cut * 3;
  }

  int nv = bnd - brk, bidx = 0;
  vector<string> vals(nv);
  for (int i = 0; i < nv; i++) {
    if (i < brk && (i > 0 || cut <= 0)) {
      vals[i].push_back('(');
      vals[i].append(base[bidx++]);
      vals[i].push_back('+');
      vals[i].append(base[bidx++]);
      vals[i].push_back(')');
    } else {
      vals[i].append(base[bidx++]);
    }
  }

  vector<char> ops(nv, '+');
  ops[nv - 1] = '\n';
  for (int i = 0; i + 1 < nv && i < brk; i += 2) {
    ops[i] = '*';
    --mul;
  }
  if (brk >= 3 && brk % 2) ops[brk - 2] = '*', --mul;

  for (int i = 0; mul; i++) {
    while (ops[i] == '*') ++i;
    ops[i] = '*';
    --mul;
  }

  cout << "possible\n";
  for (int i = 0; i < nv; i++) {
    cout << vals[i] << ops[i];
  }

  return 0;
}
