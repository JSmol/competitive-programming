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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string w;
  cin >> w;

  int n;
  cin >> n;
  vector<string> A(n);
  vector<int> C(27);
  vector<string> S;
  for (auto& a : A) {
    cin >> a;
    C[a[0] - 'a']++;
    if (*w.rbegin() == a[0]) {
      S.push_back(a);
    }
  }

  if (S.empty()) {
    cout << "?" << endl;
  } else {
    for (auto& s : S) {
      if (*s.rbegin() == *s.begin()) {
        if (C[(*s.rbegin()) - 'a'] <= 1) {
          cout << s << '!' << endl;
          return 0;
        }
      } else {
        if (C[(*s.rbegin()) - 'a'] < 1) {
          cout << s << '!' << endl;
          return 0;
        }
      }
    }
    cout << *begin(S) << endl;
  }
}

