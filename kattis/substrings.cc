#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define mp(x, y) make_pair(x, y)
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)
#define emplace emplace_back

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { o << "(" << x.fst << ", " << x.snd << ")"; return o; }
template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) { o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o; }
template<typename T> ostream& operator<<(ostream& o, const set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }

struct SA {
  int n; string str; vector<int> sarray, lcp;
  SA(string s) : n(sz(s)), str(move(s)) { /* build(); build_lcp(); */ }
  void bucket(vector<int>& a, vector<int>& b, vector<int>& r, int n, int K, int off=0) {
    vector<int> c(K+1, 0);
    for (int i = 0; i < n; i++) c[r[a[i]+off]]++;
    for (int i = 0, sum = 0; i <= K; i++) { int t = c[i]; c[i] = sum; sum += t; }
    for (int i = 0; i < n; i++) b[c[r[a[i]+off]]++] = a[i];
  }
  vector<int> build() {
    sarray.assign(n, 0); vector<int> r(2*n, 0), sa(2*n), tmp(2*n); if (n <= 1) return {};
    for (int i = 0; i < n; i++) r[i] = (int) str[i] - CHAR_MIN + 1, sa[i] = i;
    for (int k = 1; k < n; k *= 2) {
      bucket(sa, tmp, r, n, max(n, 256), k), bucket(tmp, sa, r, n, max(n, 256), 0);
      tmp[sa[0]] = 1;
      for (int i = 1; i < n; i++) {
        tmp[sa[i]] = tmp[sa[i-1]];
        if ((r[sa[i]] != r[sa[i-1]]) || (r[sa[i]+k] != r[sa[i-1]+k])) tmp[sa[i]]++;
      }
      copy(tmp.begin(), tmp.begin()+n, r.begin());
    }
    copy(sa.begin(), sa.begin()+n, sarray.begin());
    return sarray;
  }
  vector<int> build_lcp() {
    int h = 0; vector<int> rank(n); lcp.assign(n, 0);
    for (int i = 0; i < n; i++) rank[sarray[i]] = i;
    for (int i = 0; i < n; i++) {
      if (rank[i] > 0) {
        int j = sarray[rank[i] - 1];
        while (i + h < n and j + h < n and str[i+h] == str[j+h]) h++;
        lcp[rank[i]] = h;
      }
      if (h > 0) h--;
    }
    return lcp;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    SA S(s);
    auto sa = S.build();
    auto lcp = S.build_lcp();
    
    int ans = 0;
    for (int i = 1; i < sz(lcp); i++) {
      if (lcp[i-1] < lcp[i]) ans += lcp[i] - lcp[i-1];
    }

    cout << ans << endl;
  }
}

