// Title : 증가하는 리스트
// Link  : https://www.acmicpc.net/problem/1163 
// Time  : 0 ms
// Memory: 2036 KB

#include <bits/stdc++.h>

using namespace std;

vector<string_view> Tokenize(string_view str) {
  vector<string_view> tokens;
  size_t b = 0, e;
  while ((e = str.find(',', b)) != string_view::npos) {
    tokens.push_back(str.substr(b, e - b));
    b = e + 1;
  }
  tokens.push_back(str.substr(b));
  return tokens;
}

string MakeToken(string_view mask, string_view cond) {
  int nm = mask.size();
  int nc = cond.size();

  // Case 1. mask.size() < cond.size()
  if (nm < nc) return string();

  // Case 2. mask.size() > cond.size()
  if (nm > nc) {
    string s(nm, '0');
    s[0] = '1';
    for (int i = 0; i < nm; i++) {
      if (mask[i] != '?') s[i] = mask[i];
    }
    return s;
  }

  // Case 3. mask.size() == cond.size()
  bool ok = false;
  string s(mask.begin(), mask.end());
  for (int i = 0; i < nm; i++) {
    if (mask[i] == '?') {
      s[i] = cond[i];
    } else if (s[i] > cond[i]) {
      ok = true;
      for (int j = i + 1; j < nm; j++) {
        if (mask[j] == '?') s[j] = '0';
      }
      break;
    } else if (s[i] < cond[i]) {
      break;
    }
  }

  if (!ok) {
    for (int i = nm - 1; i >= 0; i--) {
      if (mask[i] != '?') continue;
      if (s[i] < '9') {
        s[i]++;
        for (int j = i + 1; j < nm; j++) {
          if (mask[j] == '?') s[j] = '0';
        }
        ok = true;
        break;
      }
    }
  }

  return ok ? s : string();
}

string Solve(vector<string_view>& tokens, string_view cond) {
  bool self = true;
  int minn = max<int>(cond.size(), 1);
  int maxx = (tokens[0].size() - 1) / 2;
  for (int i = 1; i < tokens.size(); i++) {
    if (maxx > tokens[i].size()) maxx = tokens[i].size();
    if (tokens[0].size() > tokens[i].size()) self = false;
  }

  vector<string> cands;
  cands.reserve(max<int>(maxx - minn + 1, 0) + self);
  for (int i = minn; i <= maxx; i++) {
    if (tokens[0][i] != '?' || tokens[0][i + 1] == '0') continue;
    string token = MakeToken(tokens[0].substr(0, i), cond);
    if (!token.empty()) cands.emplace_back(token);
  }
  if (self) {
    string token = MakeToken(tokens[0], cond);
    if (!token.empty()) cands.emplace_back(token);
  }
  sort(cands.begin(), cands.end());

  for (auto& token : cands) {
    if (token.size() == tokens[0].size()) {
      if (tokens.size() == 1) {
        return token;
      } else {
        string_view tmp = tokens[0];
        tokens.erase(tokens.begin());
        string s = Solve(tokens, token);
        tokens.insert(tokens.begin(), tmp);
        if (!s.empty()) return token + "," + s;
      }
    } else {
      string_view org = tokens[0];
      tokens[0] = org.substr(token.size() + 1);
      string s = Solve(tokens, token);
      tokens[0] = org;
      if (!s.empty()) return token + "," + s;
    }
  }
  return string();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  auto tokens = Tokenize(s);
  for (auto& token : tokens) {
    if (token.empty() || token[0] == '0') {
      cout << "-1" << endl;
      return 0;
    }
  }

  string ans = Solve(tokens, string());
  cout << (ans.empty() ? "-1" : ans) << endl;

  return 0;
}
