#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define st first
#define nd second

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
}

typedef long long ll;
vector<int> ans;
int A[200002];
int S[1000001];
int n;
ll s;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i], S[A[i]]++, s += A[i];

  for (int i = 0; i < n; i++) {
    ll t = s - A[i];
    if (t % 2 == 0) {
      if (t/2 == A[i] and t/2 < 1000001 and S[t/2] > 1)
        ans.push_back(i+1);
      else if (t/2 != A[i] and t/2 < 1000001 and S[t/2] > 0)
        ans.push_back(i+1);
    }
  }

  cout << ans.size() << endl;
  cout << ans << endl;
}

