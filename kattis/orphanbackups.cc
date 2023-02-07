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

template<typename T, typename U> ostream& operator<<(ostream& o, const multimap<T, U>& m) {
  o << '{'; int b = 0; for (auto& e : m) o << (b++ ? ", " : "") << e; o << '}'; return o;
}

const string R = "0123456789";

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  set<string> s1;
  map<string, set<string>> M;
  while (getline(cin, s)) {
    if (s == "") break;
    s1.insert(s);
    M[s] = {};
  }

  vector<string> ans1;
  while (getline(cin, s)) {
    if(s == "") break;
    string sub;
    int c = 0;
    int i;
    for(i = s.length()-1; i >= 0; --i){
      if(s[i] == '_') ++c;
      if(c >= 2) break;
    }
    sub = s.substr(0, i);
    if (M.count(sub)) M[sub].insert(s);
    else ans1.push_back(s);
  }
  vector<string> ans2;
  for (auto m : M) {
    if (m.snd.empty()) {
      ans2.push_back(m.fst);
    }
  }

  sort(all(ans1));
  sort(all(ans2));
  if(ans1.empty() && ans2.empty()) cout << "No mismatches." << endl;
  else{
    for (auto s : ans1) cout << "F " << s << endl;
    for (auto s : ans2) cout << "I " << s << endl;
  }
}

