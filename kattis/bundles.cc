#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << p.fst << ' ' << p.snd; return o;
}

typedef long long ll;
typedef bitset<100> bs;
const ll inf = 1ll<<60;

vector<vector<ll>> G;
vector<pair<ll, bs>> A;
ll t, n, m;

bool cmp(const pair<int, bs>& a, const pair<int, bs>& b) {
  if (a.snd.count() == b.snd.count())
    return a.fst > b.fst;
  return a.snd.count() < b.snd.count();
}

ll f(ll v) {
  ll x = A[v].fst;
  ll s = 0;
  bs bm = 0;
  for (auto& a : G[v])
    // this assert fails
    assert((bm & A[a].snd) != A[a].snd),
    bm = (bm | A[a].snd),
    s += f(a);

  if (s > 0 and bm == A[v].snd)
    x = min(s, x);

  return x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;

    A.assign(m+1, {0, 0});
    for (ll i = 1, c, k; i <= m; i++) {
      cin >> c >> k;
      A[i].fst = c;

      for (ll j = 0, x; j < k; j++) {
        cin >> x; x--;
        A[i].snd.set(x);
      }
    }

    // rm doubles
    for (ll i = 1; i <= m; i++) {
      for (ll j = i+1; j <= m; j++) {
        if (A[i].snd == A[j].snd) {
          A[i].fst = min(A[i].fst, A[j].fst); 
          A.erase(begin(A)+j);
          m--; j--;
        }
      }
    }

    // sort because i want to add the largest subsets first becuase
    // if A subset B subset C
    // then |A| <= |B| <= |C|
    // so I will only add C as a child if I have not seen B,
    // because B comes before C in sort.
    sort(begin(A)+1, end(A), cmp);
    reverse(begin(A)+1, end(A));

    // root node contains all cakes at cost inf.
    // will be removed if there exists bundle with all cakes
    A[0] = {inf, 0};
    for (int i = 0; i < n; i++) A[0].snd.set(i);

    // rm doubles
    for (ll i = 0; i <= m; i++) {
      for (ll j = i+1; j <= m; j++) {
        if (A[i].snd == A[j].snd) {
          A[i].fst = min(A[i].fst, A[j].fst); 
          A.erase(begin(A)+j);
          m--; j--;
        }
      }
    }

    // make graph, A is sorted so A[0] is root
    G.assign(m+1, {});
    for (ll i = 0; i <= m; i++) {
      for (ll j = i+1; j <= m; j++) {
        if ((A[i].snd & A[j].snd) == A[j].snd) {
          // A[j] subset A[i]
          bool p = true;
          for (auto& a : G[i])
            if ((A[a].snd & A[j].snd) == A[j].snd)
              // A[j] subset A[a]
              p = false;

          // only add child if none of my current children are superset of A[j]
          if (p) G[i].push_back(j);
        }
      }
    }

    cout << f(0) << endl;
  }
}

