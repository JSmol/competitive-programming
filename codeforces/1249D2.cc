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

template<typename T, typename U> ostream& operator<<(ostream& o, const set<T, U>& s) {
  o << '{'; int b = 0; for (auto& e : s) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; for (auto& e : m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

const int maxn = 200002;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;

  vector<int> L(n), R(n), I(n), J(n), A(maxn);
  for (int i = 0; i < n; i++) {
    cin >> L[i] >> R[i];
    I[i] = i;
    J[i] = i;
  }

  vector<int> ans;
  set<pair<int, int>, greater<>> S;
  sort(all(I), [&] (int i, int j) { return L[i] < L[j]; });
  sort(all(J), [&] (int i, int j) { return R[i] < R[j]; });
  for (int pos = 0, i = 0, j = 0, h = 0; pos < maxn; pos++) {
    while (i < n and L[I[i]] <= pos) {
      S.insert({R[I[i]], I[i]});
      i++; h++;
    }

    while (j < n and R[J[j]] < pos) {
      if (S.count({R[J[j]], J[j]})) S.erase({R[J[j]], J[j]}), h--;
      j++;
    }

    while (h > k) {
      ans.push_back(begin(S)->snd);
      S.erase(begin(S));
      h--;
    }
  }

  cout << ans.size() << endl;
  for (auto& a : ans) cout << a+1 << ' ';
  cout << endl;
}

