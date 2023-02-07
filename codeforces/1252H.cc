#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)
#define trav(a, x) for (auto& a : x) 
#define rep(i, a, b) for (int i = a; i < (b); i++) 

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << '(' << p.fst << ", " << p.snd << ')'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  o << '['; int b = 0; trav(a, v) o << (b++ ? ", " : "") << a; o << ']'; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& s) {
  o << '{'; int b = 0; trav(e, s) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; trav(e, m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

typedef long long ll;
struct segment {
  const ll id = -(1 << 60);

  ll op(ll a, ll b) {
    return max(a, b);
  }

  int n;
  vector<ll> S;
  segment(vector<ll> A, int n) : n(n) {
    S.assign(2*n, id);
    for (int i = 0; i < n; i++) S[n+i] = A[i];
    for (int i = n-1; i > 0; i--) S[i] = op(S[2*i], S[2*i+1]);
  }

  ll query(int l, int r) {
    ll ans = id;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) ans = op(ans, S[l++]);
      if (r & 1) ans = op(ans, S[--r]);
    }
    return ans;
  }
};

int n;
vector<ll> l, w;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;

  pair<ll, ll> ans = {0, 1};
  l.assign(n, 0);
  w.assign(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> w[i];
    if (l[i] < w[i]) swap(l[i], w[i]);
    if (ans.fst * 2 < w[i]*l[i] * ans.snd) ans = {w[i]*l[i], 2};
  }

  vector<int> I(n);
  iota(all(I), 0);
  sort(all(I), [&] (int i, int j) { return l[i] < l[j]; });

  vector<ll> A(n);
  for (int i = 0; i < n; i++) {
    A[i] = min(l[I[i]], w[I[i]]);
  }

  segment st(A, n);
  for (int i = 0; i < n; i++) {
    ll b = st.query(i+1, n);
    if (ans.fst < l[I[i]] * min(w[I[i]], b) * ans.snd) {
      ans = {l[I[i]] * min(w[I[i]], b), 1};
    }
  }

  if (ans.snd == 2) {
    cout << ans.fst/2 << (ans.fst % 2 == 0 ? ".0" : ".5") << endl;
  } else {
    cout << ans.fst << ".0" << endl;
  }
}

