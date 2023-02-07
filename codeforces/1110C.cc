#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << p.fst << ' ' << p.snd; return o;
}

int n, k;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  while (n--) {
    cin >> k;

    int z = __builtin_clz(k);
    int o = __builtin_popcount(k);

    if (32 - z == o) {
      int b = 1, i = 2;
      while (i * i <= k) {
        if (k % i == 0) {
          b = k / i;
          break;
        }

        i++;
      }

      cout << b << endl;
    } else {
      cout << (1 << (32 - z)) - 1 << endl;
    }
  }
}

