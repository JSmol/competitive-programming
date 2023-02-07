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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
  }

  debug(l);
  debug(r);

  int p;
  cin >> p;
  set<int> A;
  vector<int> C(n);
  for (int i = 0; i < p; i++) {
    int x;
    cin >> x;
    A.insert(x);
    for (int i = 0; i < n; i++) {
      if (l[i] <= x and x <= r[i]) C[i]++;
      if (C[i] > 2) {
        cout << "impossible" << endl;
        return 0;
      }
    }
  }

  debug(A);
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (C[i] == 1) {
      if (i+1 < n and r[i] == l[i+1] and C[i+1] < 2 and !A.count(r[i])) {
        ans.push_back(r[i]);
        A.insert(r[i]);
        C[i]++;
        C[i+1]++;
      } else {
        int j = r[i]-1;
        while (A.count(j)) j--;
        A.insert(j);
        ans.push_back(j);
        C[i]++;
      }
    } else
    if (C[i] == 0) {
      if (i+1 < n and r[i] == l[i+1] and C[i+1] < 2 and !A.count(r[i])) {
        ans.push_back(r[i]);
        A.insert(r[i]);
        C[i]++;
        C[i+1]++;
      } else {
        int j = r[i]-1;
        while (A.count(j)) j--;
        A.insert(j);
        ans.push_back(j);
        C[i]++;
      }
      int j = r[i]-1;
      while (A.count(j)) j--;
      A.insert(j);
      ans.push_back(j);
      C[i]++;
    }
  }

  cout << sz(ans) << endl;
  for (auto& a : ans) cout << a << ' ';
  cout << endl;
}

