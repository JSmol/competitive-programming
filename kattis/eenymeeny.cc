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

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; for (auto& e : m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int w = 1;
  string s;
  getline(cin, s);
  for (auto& c : s) w += c == ' ';
  
  int n;
  cin >> n;
  vector<string> A(n);
  for (auto& a : A) {
    cin >> a;
  }

  set<int> S;
  vector<int> ans1, ans2;
  int pos = 0, step = 1, p = 0;
  while (S.size() < n) {
    if (step == w and !S.count(pos)) {
      if (p) ans1.push_back(pos);
      else ans2.push_back(pos);
      S.insert(pos);
      p ^= 1;
      pos++;
      pos%=n;
      step = !S.count(pos);
    } else {
      pos++;
      pos%=n;
      step += !S.count(pos);
    }
  }

  cout << ans2.size() << endl;
  for (auto& a : ans2) cout << A[a] << endl;
  cout << ans1.size() << endl;
  for (auto& a : ans1) cout << A[a] << endl;
}

