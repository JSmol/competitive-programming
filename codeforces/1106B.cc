#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? "\n" : "") << a; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << p.fst << ' ' << p.snd; return o;
}

typedef long long ll;
ll n, m;
vector<ll> A, C, ans;
vector<pair<ll, ll>> B;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  A.assign(n, 0);
  C.assign(n, 0);
  for (auto& a : A) cin >> a;

  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
  for (ll i = 0; i < n; i++) cin >> C[i], Q.push({C[i], i});

  B.assign(m, {});
  ans.assign(m, 0);
  for (auto& b : B) cin >> b.fst >> b.snd;

  for (ll j = 0; j < m; j++) {
    auto& b = B[j];
    ll i = b.fst - 1;
    if (A[i] > b.snd) {
      A[i] -= b.snd;
      ans[j] += C[i] * b.snd;
    } else {
      ans[j] += C[i] * A[i];
      b.snd -= A[i];
      A[i] = 0;
      while (true) {
        if (Q.empty()) {
          if (b.snd > 0)
            ans[j] = 0;
          break;
        }

        i = Q.top().snd;
        if (A[i] > b.snd) {
          A[i] -= b.snd;
          ans[j] += C[i] * b.snd;
          break;
        } else {
          ans[j] += C[i] * A[i];
          b.snd -= A[i];
          A[i] = 0;
          Q.pop();
        }
      }
    }
  }

  cout << ans << endl;
}

