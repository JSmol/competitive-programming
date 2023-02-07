#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define mp(x, y) make_pair(x, y)
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { o << "(" << x.fst << ", " << x.snd << ")"; return o; }
template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) { o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o; }
template<typename T> ostream& operator<<(ostream& o, const set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
double time() { return double(clock()) / CLOCKS_PER_SEC; }

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    int p = 0;
    for (int i = 0; i+1 < n; i++) {
      if (a[i] != a[i+1]) p = 1;
    }
  
    if (!p) {
      cout << 1 << endl;
      for (int i = 0; i < n; i++)
        cout << 1 << " \n"[i == n-1];

      continue;
    }

    if (n%2==0) {
      cout << 2 << endl;
      for (int i = 0; i < n; i++)
        cout << (i%2)+1 << " \n"[i == n-1];

      continue;
    }

    p = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == a[(i+1) % n]) {
        p = 1;
        cout << 2 << endl;
        vector<int> x(n);
        for (int j = 0; j < n; j++) {
          x[(i+1+j)%n] = j%2;
        }

        x[i] = x[(i+1) % n];
        for (int j = 0; j < n; j++) {
          cout << x[j]+1 << " \n"[j == n-1];
        }

        break;
      }
    }
    
    if (p) continue;

    cout << 3 << endl;
    if (n % 3 == 1) {
      for (int i = 0; i < n-1; i++)
        cout << (i%3)+1 << " \n"[i == n-1];
      cout << 2 << endl;
    } else {
      for (int i = 0; i < n; i++)
        cout << (i%3)+1 << " \n"[i == n-1];
    }
  }
}

