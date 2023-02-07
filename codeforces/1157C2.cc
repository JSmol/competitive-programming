
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

int n;
vector<int> A;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  A.assign(n, 0);
  for (auto& a : A) cin >> a;
  string ans;
  int k = 0, i = 0, j = n-1;
  while (i <= j) {
    if (k < A[i] and k < A[j] and A[i] != A[j]) {
      if (k < A[i] and A[i] < A[j]) {
        ans += "L";
        k = A[i];
        i++;
      } else {
        ans += "R";
        k = A[j];
        j--;
      }
    } else {
      int a = i, b = j, s = 0, t = 0, l = k;
      while (i <= b and k < A[i]) k = A[i], s++, i++;
      while (a <= j and l < A[j]) l = A[j], t++, j--;
      if (s > t) ans += string(s, 'L');
      else ans += string(t, 'R');
      break;
    }
  }
  cout << ans.length() << endl;
  cout << ans << endl;
}


