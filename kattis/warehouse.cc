#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)
#define trav(a, x) for (auto& a : x) 
#define rep(i, a, b) for (int i = a; i < (b); i++) 

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  o << '['; int b = 0; trav(a, v) o << (b++ ? ", " : "") << a; o << ']'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << '(' << p.fst << ", " << p.snd << ')'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& s) {
  o << '{'; int b = 0; trav(e, s) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; trav(e, m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<string, int> A;
    rep(i, 0, n) {
      string s; int x;
      cin >> s >> x;
      if (A.count(s)) A[s] += x;
      else A[s] = x;
    }

    vector<pair<int, string>> ans;
    trav(a, A) ans.push_back({a.snd, a.fst});
    sort(all(ans), [] (auto a, auto b) { if (a.fst == b.fst) return a.snd < b.snd; else return a.fst > b.fst; });
    cout << sz(ans) << endl;
    trav(a, ans) cout << a.snd << ' ' << a.fst << endl;
  }
}

