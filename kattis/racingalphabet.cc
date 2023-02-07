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

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& m) {
  o << '{'; int b = 0; for (auto& e : m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

const long double PI = acos(-1);

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  map<char, int> m;
  m[' '] = 27;
  m['\''] = 28;
  
  for(char c = 'A'; c <= 'Z'; ++c){
    m[c] = (int)(c-'A'+1);
  }

  int n; cin >> n; cin.ignore();
  for(int i = 0; i < n; ++i){
    string s; getline(cin, s, '\n');
    int num = 0;
    for(int j = 1; j < s.length(); ++j){
      num += min((m[s[j]]-m[s[j-1]]+28)%28, (m[s[j-1]]-m[s[j]]+28)%28);
      //debug(min((m[s[j]]-m[s[j-1]]+28)%28, (m[s[j-1]]-m[s[j]]+28)%28)); 
    }
    long double ans = (num/7.0*PI)+(s.length());
    cout << fixed << setprecision(9) << ans << endl;
  }



}

