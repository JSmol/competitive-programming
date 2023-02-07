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

const string alph = "qwertyuiopasdfghjklzxcvbnm";

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  set<string> S;
  while (cin >> s) {
    int n = s.length();
    string t;
    for (int i = 0; i < n; i++) {
      if (isalpha(s[i])) {
        t += tolower(s[i]);
      }
    }

    if (t == "") continue;
    else S.insert(t);
  }

  map<string, set<string>> ans;
  for (string s : S) {
    int n = s.length();
    ans[s] = {};
    for (int i = 0; i < n; i++) {
      if (S.count(s.substr(0, i) + s.substr(i+1))) ans[s].insert(s.substr(0, i) + s.substr(i+1));
      if (i+1 < n) {
        string t = s;
        swap(t[i], t[i+1]);
        if (S.count(t)) ans[s].insert(t);
      }

      for (auto c : alph) {
        string t = s;
        t[i] = c;
        if (S.count(t)) ans[s].insert(t);
      }
      
      for (auto c : alph) {
        string t = s.substr(0, i) + c + s.substr(i);
        if (S.count(t)) ans[s].insert(t);
      }
    }

    for (auto c : alph) {
      string t = s + c;
      if (S.count(t)) ans[s].insert(t);
    }

    ans[s].erase(s);
  }
  
  bool p = false;
  for (auto& a : ans) {
    if (!a.snd.empty()) {
      p = true;
      cout << a.fst << ": ";
      for (auto t : a.snd) {
        cout << t << ' ';
      }
      cout << endl;
    }
  }

  if (!p) cout << "***" << endl;
}

