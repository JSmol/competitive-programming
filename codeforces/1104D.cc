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

typedef long long ll;
string s;
char res;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  while (cin >> s and s != "end") {
    if (s == "mistake") return 0;

    cout << '?' << ' ' << 2 << ' ' << 1 << endl;
    fflush(stdout);
    cin >> res;
    if (res == 'y') {
      cout << '!' << ' ' << 2 << endl;
      fflush(stdout);
      continue;
    } else {
      cout << '?' << ' ' << 1 << ' ' << 2 << endl;
      fflush(stdout);
      cin >> res;
      if (res == 'x') {
        cout << '!' << ' ' << 1 << endl;
        fflush(stdout);
        continue;
      }
    }

    ll x = 2, y = 4;
    while (true) {
      cout << '?' << ' ' << x << ' ' << y << endl;
      fflush(stdout);

      cin >> res;
      if (res == 'y')
        x <<= 1, y <<= 1;
      else
        break;
    }

    while (true) {
      int mid = (y+x)/2;
      if (y - mid == 1) {
        x = mid; break;
      }

      cout << '?' << ' ' << x << ' ' << mid << endl;
      fflush(stdout);
      cin >> res;
      if (res == 'x')
        y = mid;
      else
        x = mid;
    }

    cout << '?' << ' ' << x << ' ' << y << endl;
    fflush(stdout);

    cin >> res;
    if (res == 'x')
      cout << '!' << ' ' << y << endl;
    else 
      cout << '!' << ' ' << x << endl;

    fflush(stdout);
  }
}

