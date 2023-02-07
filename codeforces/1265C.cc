#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { 
  o << "(" << x.fst << ", " << x.snd << ")"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) {
  o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& a : A) cin >> a;
    if (n < 5) {
      cout << "0 0 0" << endl;
      continue;
    }

    vector<int> ans(3);
    int g = A[0];
    int i = 0;
    while (i < n and A[i] == g) {
      ans[0]++;
      i++;
    }

    if (i >= n) {
      cout << "0 0 0" << endl;
      continue;
    }

    int s = A[i];
    while (i < n and (ans[1] <= ans[0] or A[i] == s)) {
      s = A[i];
      ans[1]++;
      i++;
    }

    if (i >= n) {
      cout << "0 0 0" << endl;
      continue;
    }

    int b = A[i];
    while (i < n and (ans[2] <= ans[0] or A[i] == b)) {
      b = A[i];
      ans[2]++;
      i++;
    }

    if (ans[0] + ans[1] + ans[2] > n/2) {
      cout << "0 0 0" << endl;
      continue;
    }

    while (true) {
      int c = 0;
      int e = A[i];
      while (i < n and A[i] == e) {
        c++; i++;
      }
      if (ans[0]+ans[1]+ans[2]+c <= n/2) ans[2] += c;
      else break;
    }

    for (auto& a : ans) cout << a << ' ';
    cout << endl;
  }
}

