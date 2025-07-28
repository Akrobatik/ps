// Title : 세그먼트 트리보다도 바･로･너･♡
// Link  : https://www.acmicpc.net/problem/34075 
// Time  : 0 ms
// Memory: 2176 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<string> algo[32];
  while (n--) {
    string s;
    int x;
    cin >> s >> x;
    algo[x].push_back(s);
  }

  for (int i = 1; i <= 30; i++) {
    sort(algo[i].begin(), algo[i].end());
  }

  int m;
  cin >> m;
  unordered_map<string, int> member;
  while (m--) {
    string s;
    int x;
    cin >> s >> x;
    member[s] = x;
  }

  int q;
  string name;
  cin >> q;
  vector<string> likes;
  while (q--) {
    string a, b, c;
    cin >> a >> b >> c;
    if (c[0] == 'c') {
      name = a;
      cout << "hai!\n";
    } else {
      int lv = member[name];
      likes = algo[lv];
      for (int i = 1; likes.size() < 2; i++) {
        vector<string> tmp;
        if (lv - i >= 0 && lv + i <= 30) {
          auto& lvec = algo[lv - i];
          auto& rvec = algo[lv + i];
          if (!lvec.empty() && !rvec.empty()) {
            vector<string> tmp;
            tmp.resize(lvec.size() + rvec.size());
            merge(lvec.begin(), lvec.end(), rvec.begin(), rvec.end(), tmp.begin());
            auto it = tmp.begin();
            while (likes.size() < 2) likes.push_back(*it++);
          } else if (!lvec.empty()) {
            int old = likes.size();
            likes.resize(old + lvec.size());
            copy(lvec.begin(), lvec.end(), likes.begin() + old);
          } else if (!rvec.empty()) {
            int old = likes.size();
            likes.resize(old + rvec.size());
            copy(rvec.begin(), rvec.end(), likes.begin() + old);
          }
        } else if (lv - i >= 0) {
          auto& lvec = algo[lv - i];
          int old = likes.size();
          likes.resize(old + lvec.size());
          copy(lvec.begin(), lvec.end(), likes.begin() + old);
        } else if (lv + i <= 30) {
          auto& rvec = algo[lv + i];
          int old = likes.size();
          likes.resize(old + rvec.size());
          copy(rvec.begin(), rvec.end(), likes.begin() + old);
        }
      }
      cout << likes[1] << " yori mo " << likes[0] << "\n";
    }
  }

  return 0;
}
