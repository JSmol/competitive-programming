#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define all(X) begin(X), end(X)
#define sz(X) X.size()

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

int flip(int x) {
  string t = "";
  string s = to_string(x);
  for (int i = sz(s)-1; i >= 0; i--) {
    if (s[i] == '2') t += '2';
    if (s[i] == '5') t += '5';
    if (s[i] == '6') t += '9';
    if (s[i] == '9') t += '6';
    if (s[i] == '0') t += '0';
    if (s[i] == '1') t += '1';
    if (s[i] == '8') t += '8';
    if (s[i] == '7' or s[i] == '4' or s[i] == '3') return -1;
  }
  return stoi(t);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, s;
  cin >> n >> s;
  vector<pair<int, int>> A(n);
  for (auto& a : A) cin >> a.fst;

  sort(all(A));
  map<int, vector<int>> M;
  for (int i = 0; i < n; i++) {
    A[i].snd = i;
    if (M.count(A[i].fst)) M[A[i].fst].push_back(i);
    else M[A[i].fst] = {i};
    int x = flip(A[i].fst);
    A.push_back({x, i});
    if (x == -1) continue;
    if (M.count(x)) M[x].push_back(i);
    else M[x] = {i};
  }

  for (int i = 0; i < sz(A); i++) {
    int r = s - A[i].fst;
    if (!M.count(r)) continue;
    for (auto& j : M[r]) {
      if (A[i].snd != j) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }

  cout << "NO" << endl;
  return 0;
}

