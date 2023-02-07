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

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; for (auto& e : m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

typedef long long ll;
ll X[101010];

ll fexp(ll x, ll p, ll mod) {
  ll& r = X[p];
  assert(r >= 0);
  if (r != 0) return r;

  r = 1;
  while (p > 0) {
    if (p & 1) p -= 1, r = (r * x) % mod;
    else p >>= 1, x = (x * x) % mod;
  }
  r %= mod;
  return r;
}

pair<ll, ll> egcd(ll a, ll b) {
  if (b > a) swap(a, b);
  ll s = 0, t = 1, u = 1, v = 0, q = 0;
  while (b != 0) {
    q = a/b;
    swap(a, b);
    b = b % a;
    swap(s, u);
    s = s - u * q;
    swap(t, v);
    t = t - v * q;
  }
  return {u, v};
}

ll modinv(ll a, ll m) {
  return (egcd(a, m).snd + m) % m;
}

const ll alph = 26 + 1;

// const ll prime = 100000000003;
const ll prime = 1000000007;
const ll inverse = modinv(alph, prime) % prime;

// "abc" -> 1*27^0 + 2*27^1 + 3*27^2
ll h(string s) {
  ll hash = 0;
  for (int i = 0; i < (int) s.length(); i++)
    hash += ((s[i] - 'A' + 1) * fexp(alph, i, prime)) % prime;
  return hash % prime;
}

// strings and strings w/ nvwls
string S[101010], N[101010];
ll HN[101010];
int C[101010]; 
int dp[303030];
int b[303030];
vector<int> matches[303030];

const int inf = (1 << 25);

set<int> lengths;
map<ll, int> M;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  const set<char> vowels = {'A', 'E', 'I', 'O', 'U'};
  assert(inverse*alph % prime == 1);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> S[i];
    for (auto& c : S[i]) {
      if (vowels.count(c)) C[i]++;
      else N[i] += c;
    }

    HN[i] = h(N[i]);
    lengths.insert((int) N[i].length());
    if (M.count(HN[i]) and C[M[HN[i]]] < C[i]) M[HN[i]] = i;
    if (!M.count(HN[i])) M[HN[i]] = i;
  }

  string s;
  cin >> s;
  n = (int) s.length();
  for (auto& len : lengths) {
    if (len > n) continue;
    ll hs = h(s.substr(0, len));
    if (M.count(hs)) matches[0].push_back(M[hs]);
    for (int i = len; i < n; i++) {
      hs = (hs + ((s[i] - 'A' + 1) % prime) * fexp(alph, len, prime)) % prime;
      hs = (hs - (s[i-len] - 'A' + 1) + prime) % prime;
      hs = (hs * inverse) % prime;
      if (M.count(hs)) matches[i-len+1].push_back(M[hs]);
    }
  }

  // dp[i] = max vowels with substr s[i .. n]
  fill(dp, dp+n+1, -inf);
  fill(b, b+n+1, -1);
  dp[n] = 0;
  for (int i = n-1; i >= 0; i--) {
    for (int j : matches[i]) {
      if (dp[i + N[j].length()] == -inf) continue;
      int v = dp[i + N[j].length()] + C[j];
      if (dp[i] < v) {
        dp[i] = v;
        b[i] = j;
      }
    }
  }

  for (int i = 0; i < n; i = i + (int) N[b[i]].length()) {
    assert(b[i] >= 0);
    cout << S[b[i]] << ' ';
  }
  cout << endl;
}

