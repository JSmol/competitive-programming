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

int b, k;
vector<int> A;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> b >> k;
  A.assign(k, 0);
  for (auto& a : A) cin >> a;

  if (b % 2 == 0) {
    if (A[k-1] % 2 == 0)
      cout << "even" << endl;
    else
      cout << "odd" << endl;
  } else { 
    int c = 0;
    for (auto& a : A)
      if (a % 2)
        c++;

    if (c % 2 == 0)
      cout << "even" << endl;
    else
      cout << "odd" << endl;
  }
}

