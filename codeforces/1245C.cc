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

typedef long long ll;
const ll mod = 1e9+7;
ll dp[101010];
string s;
ll f(int i) {
  if (i == sz(s)) return 1;
  if (dp[i] != -1) return dp[i];
  if (s[i] == 'n' and s[i+1] == 'n') return dp[i] = (f(i+1) + f(i+2)) % mod;
  if (s[i] == 'u' and s[i+1] == 'u') return dp[i] = (f(i+1) + f(i+2)) % mod;
  return dp[i] = f(i+1) % mod;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> s;
  trav(c, s) if (c == 'm' or c == 'w') return cout << 0 << endl, 0;
  fill(dp, dp + 101010, -1);
  cout << f(0) % mod << endl;
}

