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
int n, k;
int A[202020];
string b;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> A[i];
  cin >> b;
  
  ll ans = 0;
  for (int i = 0, j = 0; i < n; i = j) {
    j = i;
    while (j < n and b[i] == b[j]) j++;

    sort(A+i, A+j);
    for (int l = 1; l <= min(k, j-i); l++) 
      if (j-l >= i)
        ans += A[j-l];
  }

  cout << ans << endl;
}

