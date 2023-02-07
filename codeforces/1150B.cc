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
char A[55][55];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (A[i][j] == '.') {
        for (int k : {-1, 0, 1}) {
          for (int l : {-1, 0, 1}) {
            if (k == -1 and l == -1) continue;
            if (k == -1 and l == 1) continue;
            if (k == 1 and l == -1) continue;
            if (k == 1 and l == 1) continue;

            if (i+k+1 < n and i+k+1 >= 0 and j+l < n and j+l >= 0 and A[i+k+1][j+l] == '.') {
              A[i+k+1][j+l] = '#';
            } else {
              cout << "NO" << endl;
              return 0;
            }
          }
        }
      }
    }
  }

  cout << "YES" << endl;
}

