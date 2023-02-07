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

struct segment {
  const int id = -(1 << 30);

  int op(int a, int b) {
    return max(a, b);
  }

  int n;
  vector<int> S;
  segment(vector<int> A, int n) : n(n) {
    S.assign(2*n, id);
    for (int i = 0; i < n; i++) S[n+i] = A[i];
    for (int i = n-1; i > 0; i--) S[i] = op(S[2*i], S[2*i+1]);
  }

  // query range A[l], ... , A[r-1].
  int query(int l, int r) {
    int ans = id;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) ans = op(ans, S[l++]);
      if (r & 1) ans = op(ans, S[--r]);
    }
    return ans;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& a : A) cin >> a;

    int m;
    cin >> m;
    vector<pair<int, int>> H(m);
    for (int i = 0; i < m; i++) {
      cin >> H[i].fst >> H[i].snd;
    }

    sort(all(H));
    vector<int> S(m);
    for (int i = 0; i < m; i++) S[i] = H[i].snd;

    segment st(S, m);
    int ans = 0;

    for (int i = 0, j = 0; i < n; i = j) {

      int c = 0;
      int k = 0;
      int P = A[i];

      j = i;
      while (j < n) {
        P = max(P, A[j]);
        k = lower_bound(all(H), make_pair(P, 0)) - begin(H);
        if (k >= m or c >= st.query(k, m)) break;
        j++; c++;
      }

      if (c == 0) {
        ans = -1;
        break;
      } else {
        ans++;
      }
    }
  
    cout << ans << endl;
  }
}

