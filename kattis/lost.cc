#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
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
int n, m;
vector<vector<pair<int, int>>> A;
map<string, int> M;
vector<string> N;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  N.assign(n+1, {});
  N[0] = "English";
  M[N[0]] = 0;
  for (int i = 0; i < n; i++) {
    cin >> N[i+1];
    M[N[i+1]] = i+1;
  }

  A.assign(n+1, {});
  for (int i = 0; i < m; i++) {
    string s, t;
    int c;
    cin >> s >> t >> c;
    A[M[s]].push_back({M[t], c});
    A[M[t]].push_back({M[s], c});
  }

  ll ans = 0;
  queue<int> Q;
  vector<int> V(n+1, 0);
  V[0] = 1;
  Q.push(0);
  while (!Q.empty()) {
    vector<pair<int, int>> X;
    while (!Q.empty()) {
      int v = Q.front();
      Q.pop();
      for (auto& a : A[v]) {
        X.push_back({a.snd, a.fst});
      }
    }

    sort(all(X));
    for (auto& x : X) {
      if (!V[x.snd]) {
        V[x.snd] = 1;
        ans += x.fst;
        Q.push(x.snd);
      }
    }
  }
  
  for (auto& d : V) {
    if (!d) ans = -1;
  }

  if (ans == -1) cout << "Impossible" << endl;
  else cout << ans << endl;
}




