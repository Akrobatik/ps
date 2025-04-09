// Title : 회장 호출하기
// Link  : https://www.acmicpc.net/problem/33075 
// Time  : 88 ms
// Memory: 13676 KB

#include <bits/stdc++.h>

using namespace std;

int Distance(int a, int b, int k) {
  if (a > b) swap(a, b);
  return min<int>(b - a, a + k - b);
}

int Distance(pair<int, int> ab, int k) {
  auto [a, b] = ab;
  return Distance(a, b, k);
}

// av - bv
pair<int, int> Candidate(int a, int k, int delta) {
  int mid = k >> 1;
  if (k & 1) {
    if ((mid & 1) == (delta & 1)) {
      int ad = (delta + mid) >> 1;
      int ar = (a + ad - 1) % k + 1;
      return {ar, ar};
    } else {
      int ad = (delta + mid + 1) >> 1;
      int al = (a + k - ad - 1) % k + 1;
      return {al, al};
    }
  } else {
    int ad = (delta + mid) >> 1;
    int al = (a + k - ad - 1) % k + 1;
    int ar = (a + ad - 1) % k + 1;
    return {al, ar};
  }
}

int Query(const vector<int>& arr) {
  cout << "?";
  for (auto e : arr) {
    cout << " " << e;
  }
  cout << endl;

  int res;
  cin >> res;
  return res;
}

int Query(int a, int ax, const vector<int>& arr) {
  cout << "?";
  for (int i = 0; i < arr.size(); i++) {
    if (i == a) {
      cout << " " << ax;
    } else {
      cout << " " << arr[i];
    }
  }
  cout << endl;

  int res;
  cin >> res;
  return res;
}

int Query(const vector<pair<int, int>>& changes, const vector<int>& arr) {
  vector<int> queries(arr.size(), -1);
  for (auto [i, x] : changes) {
    queries[i] = x;
  }
  for (int i = 0; i < arr.size(); i++) {
    if (queries[i] != -1) continue;
    queries[i] = arr[i];
  }

  cout << "?";
  for (auto e : queries) cout << " " << e;
  cout << endl;

  int res;
  cin >> res;
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  mt19937 gen(random_device{}());

  int n, k;
  cin >> n >> k;

  vector<int> arr(n);
  for (auto& e : arr) e = gen() % k + 1;

  int base = Query(arr);
  vector<bool> memo(n);
  vector<int> ans(n);
  vector<tuple<int, int, int, int>> cands;
  for (int i = 0; i < n; i++) {
    int a = arr[i], b = (a + (k >> 1) - 1) % k + 1;
    auto [l, r] = Candidate(a, k, base - Query(i, b, arr));
    if (l == r) {
      memo[i] = true;
      ans[i] = l;
    } else {
      cands.push_back({Distance(l, r, k), l, r, i});
    }
  }

  sort(cands.begin(), cands.end());
  for (int i = 0; i < cands.size(); i++) {
    if (memo[get<3>(cands[i])]) continue;
    memo[get<3>(cands[i])] = true;

    vector<tuple<int, int, int, int>> cur{cands[i]};
    int sum = get<0>(cands[i]);
    for (int j = i + 1; j < cands.size(); j++) {
      if (memo[get<3>(cands[j])] || sum >= get<0>(cands[j])) continue;
      memo[get<3>(cands[j])] = true;
      cur.push_back(cands[j]);
      sum += get<0>(cands[j]);
    }

    int cbase = base;
    vector<pair<int, int>> changes(cur.size());
    for (int j = 0; j < cur.size(); j++) {
      auto [cd, cl, cr, ci] = cur[j];
      cbase -= Distance(cl, arr[ci], k);
      changes[j] = {ci, cl};
    }

    int res = Query(changes, arr) - cbase;
    for (auto [ad, al, ar, ai] : views::reverse(cur)) {
      if (res >= ad) {
        res -= ad;
        ans[ai] = ar;
      } else {
        ans[ai] = al;
      }
    }
  }

  cout << "!";
  for (auto e : ans) cout << " " << e;
  cout << endl;

  return 0;
}
