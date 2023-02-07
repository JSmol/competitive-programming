#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second
#define all(X) begin(X), end(X)

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  o << '['; int b = 0; for (const auto& a : v) o << (b++ ? ", " : "") << a; o << ']'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << '(' << p.fst << ", " << p.snd << ')'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& s) {
  o << '{'; int b = 0; for (auto& e : s) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

int n;
string s, t;
vector<pair<char, int>> l, r;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  cin >> s >> t;
  l.assign(n, {});
  r.assign(n, {});
  for (int i = 0; i < n; i++) {
    l[i] = {s[i], i};
    r[i] = {t[i], i};
  }

  sort(all(l));
  sort(all(r));
  vector<pair<int, int>> ans;
  vector<bool> ul(n), ur(n);

  for (int i = 0, j = 0; i < n; i++) {
    if (l[i].fst == '?') continue;
    while (j < n and (ur[j] or r[j].fst < l[i].fst)) j++;
    if (j < n and l[i].fst == r[j].fst) {
      ans.push_back({l[i].snd, r[j].snd});
      assert(!ul[i] and !ur[j]);
      ul[i] = ur[j] = true;
    }
  }

  int i = 0, j = n-1;
  while (i < n and !ul[i] and l[i].fst == '?') {
    while (j >= 0 and ur[j]) j--;
    if (j >= 0 and !ur[j]) {
      ans.push_back({l[i].snd, r[j].snd});
      assert(!ul[i] and !ur[j]);
      ul[i] = ur[j] = true;
    }

    i++;
  }

  i = 0, j = n-1;
  while (i < n and !ur[i] and r[i].fst == '?') {
    while (j >= 0 and ul[j]) j--;
    if (j >= 0 and !ul[j]) {
      ans.push_back({l[j].snd, r[i].snd});
      assert(!ul[j] and !ur[i]);
      ul[j] = ur[i] = true;
    }

    i++;
  }

  cout << ans.size() << endl;
  for (auto& a : ans) cout << a.fst + 1 << ' ' << a.snd + 1 << endl;
}

