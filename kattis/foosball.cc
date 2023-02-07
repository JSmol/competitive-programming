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

string W[2], B[2];
map<string, int> M;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  cin >> W[0] >> B[0] >> W[1] >> B[1];
  M[W[0]] = -4;
  M[W[1]] = -3;
  M[B[0]] = -2;
  M[B[1]] = -1;

  queue<string> Q;
  for (int i = 4; i < n; i++) {
    string q;
    cin >> q;
    M[q] = -5;
    Q.push(q);
  } 

  string s;
  cin >> s;
  n = s.length();

  vector<int> V(n);
  for (int i = 0, j = 0; i < n; i = j) {
    j = i;
    while (j < n and s[i] == s[j]) j++;
    V[i] = j-i;
  }


  vector<pair<string, string>> ans;
  int best = *max_element(all(V));
  for (int i = 0; i < n; i++) {
    auto& c = s[i];
    if (V[i] == best) {
      if (c == 'W') {
        if (M[W[0]] < M[W[1]]) ans.push_back({W[0], W[1]});
        else ans.push_back({W[1], W[0]});
      } else {
        if (M[B[0]] < M[B[1]]) ans.push_back({B[0], B[1]});
        else ans.push_back({B[1], B[0]});
      }
    }

    if (c == 'W') {
      swap(W[0], W[1]);

      Q.push(B[1]);
      M[B[1]] = -5;
      B[1] = B[0];
      B[0] = Q.front();
      M[B[0]] = i;
      Q.pop();
    } else {
      swap(B[0], B[1]);

      Q.push(W[1]);
      M[W[1]] = -5;
      W[1] = W[0];
      W[0] = Q.front();
      M[W[0]] = i;
      Q.pop();
    }
  }

  for (auto& a : ans) cout << a.fst << ' ' << a.snd << endl;
}

