#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define mp(x, y) make_pair(x, y)
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)

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
double time() { return double(clock()) / CLOCKS_PER_SEC; }

/*  KMP string matching O(n)
 *  pi[x] = length of longest commont prefix of s that is also a (proper) suffix
 *  calc_pi("alabala") => {-1, 0, 0, 1, 0, 1, 2, 3}
 *  match("atoat", "atoatoat") => {4, 7}
 */

vector<int> calc_pi(string s) {
  int n = sz(s);
  vector<int> pi(n + 1, -1);
  for (int i = 0; i < n; ++i) {
    int j = pi[i]; while (j != -1 and s[j] != s[i]) j = pi[j];
    pi[i + 1] = j + 1;
  }
  return pi;
}

vector<int> match(string text, string pat) {
  vector<int> pi = calc_pi(pat), ret; int j = 0;
  for (int i = 0; i < sz(text); ++i) {
    while (j != -1 and pat[j] != text[i]) j = pi[j];
    if (++j == sz(pat)) ret.push_back(i), j = pi[j];
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s, t; while (getline(cin, s) and getline(cin, t)) {
    auto x = match(t, s);
    for (int i = 0; i < sz(x); i++)
      cout << x[i]-sz(s)+1 << ' ';
    cout << endl;
  }
}

