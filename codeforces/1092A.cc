#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
}

int n, k, t;
const string a = "abcdefghijklmnopqrstuvwxyz";

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    string s;
    int j = 0;
    for (int i = 0; i < n; i++)
      s += a[j], j = (j + 1) % k;
    
    cout << s << endl;
  }

}

