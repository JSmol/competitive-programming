#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second
#define mp make_pair

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << p.fst << ' ' << p.snd; return o;
}

int n, k;
set<int> S;
vector<int> A;
vector<pair<pair<int, int>, int>> K;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  A.assign(n, 0);
  for (auto& a : A) cin >> a;

  K.assign(k, {{0, 0}, 0});

  int l = 0, c = 0;
  while (c < n) {
    for (int i = 0; i < k; i++) {
      auto& t = K[i].fst;
      int& j = K[i].snd;
      if (t.fst == t.snd and l < n) t.fst = 0, t.snd = A[l], j = l, l++;
      else if (t.fst == t.snd) t.fst = t.snd = j = 0;
    }

    int m = 1 << 30;
    for (int i = 0; i < k; i++) {
      auto& t = K[i].fst;
      if (t != mp(0,0)) m = min(m, t.snd - t.fst);
    }

    for (int i = 0; i < k; i++) {
      auto& t = K[i].fst;
      int& j = K[i].snd;
      int d = (c*100+(n/2))/n;

      if (t != mp(0,0) and t.fst + 1 <= d and d <= min(t.fst+m, t.snd)) S.insert(j);
    }

    for (int i = 0; i < k; i++) {
      auto& t = K[i].fst;
      if (t != mp(0,0)) {
        t.fst += m;
        if (t.fst == t.snd) c++;
      }
    }
  }
  cout << S.size() << endl;
}

