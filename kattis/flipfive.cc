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
  int p;
  cin >> p;
  while (p--) {
    int t = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        char x;
        cin >> x;
        if (x == '*') t |= (1 << (i*3 + j));
      }
    }
    
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    vector<bool> V(1 << 9);
    while (!Q.empty()) {
      int v = Q.front().fst; int m = Q.front().snd;
      Q.pop();

      if (v == t) {
        cout << m << endl;
        break;
      }

      if (V[v]) continue;
      V[v] = 1;

      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          int a = v ^ (1 << (i*3 + j));
          for (int k : {-1, 1}) {
            if (0 <= i + k and i + k < 3) a = a ^ (1 << ((i+k)*3 + j));
            if (0 <= j + k and j + k < 3) a = a ^ (1 << (i*3 + (j+k)));
          }
          Q.push({a, m+1});
        }
      }
    }
  }
}

