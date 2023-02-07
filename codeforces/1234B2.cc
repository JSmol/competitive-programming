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
  int n, k;
  cin >> n >> k;

  set<int> S;
  queue<int> Q;
  while (n--) {
    int a;
    cin >> a;
    if (S.count(a)) continue;
    else {
      if (Q.size() == k) {
        S.erase(Q.front());
        Q.pop();
      }
      S.insert(a);
      Q.push(a);
    }
  }

  cout << S.size() << endl;

  vector<int> ans;
  while (!Q.empty()) {
    ans.push_back(Q.front());
    Q.pop();
  }

  reverse(all(ans));
  for (auto& a : ans) cout << a << ' ';
  cout << endl;
}

