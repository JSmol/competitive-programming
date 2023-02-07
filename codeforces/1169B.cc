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
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> A(m);
  for (int i = 0; i < m; i++) {
    cin >> A[i].fst >> A[i].snd;
  }

  int x = A[0].fst;
  int j = -1;
  for (int i = 0; i < m; i++) {
    if (x != A[i].fst and x != A[i].snd) {
      j = i;
      break;
    }
  }

  if (j == -1) {
    cout << "YES" << endl;
    return 0;
  }

  bool ans = true;
  int y = A[j].fst;
  for (int i = 0; i < m; i++) {
    if (x != A[i].fst and x != A[i].snd and y != A[i].fst and y != A[i].snd) {
      ans = false;
      break;
    }
  }

  if (ans) {
    cout << "YES" << endl;
    return 0;
  }

  ans = true;
  y = A[j].snd;
  for (int i = 0; i < m; i++) {
    if (x != A[i].fst and x != A[i].snd and y != A[i].fst and y != A[i].snd) {
      ans = false;
      break;
    }
  }

  if (ans) {
    cout << "YES" << endl;
    return 0;
  }

  // --
  x = A[0].snd;
  j = -1;
  for (int i = 0; i < m; i++) {
    if (x != A[i].fst and x != A[i].snd) {
      j = i;
      break;
    }
  }

  if (j == -1) {
    cout << "YES" << endl;
    return 0;
  }

  ans = true;
  y = A[j].fst;
  for (int i = 0; i < m; i++) {
    if (x != A[i].fst and x != A[i].snd and y != A[i].fst and y != A[i].snd) {
      ans = false;
      break;
    }
  }

  if (ans) {
    cout << "YES" << endl;
    return 0;
  }
  
  ans = true;
  y = A[j].snd;
  for (int i = 0; i < m; i++) {
    if (x != A[i].fst and x != A[i].snd and y != A[i].fst and y != A[i].snd) {
      ans = false;
      break;
    }
  }

  if (ans) {
    cout << "YES" << endl;
    return 0;
  }

  cout << "NO" << endl;
}

