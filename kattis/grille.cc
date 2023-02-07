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

int n;

bool seen[14][14] = {0};
char A[14][14];
char B[14][14];
char ans[14][14];

void r(int p){
  int c = n-1;
  if(p%2 == 0){
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){ 
        B[j][c] = A[i][j]; 
      }
      --c;
    }
  }
  else{
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){ 
        A[j][c] = B[i][j]; 
      }
      --c;
    }
  }
}

void print(int k)
{
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j)
      cout << B[i][j];
    cout << endl;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  cin >> n;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      cin >> A[i][j];
   
  string s; cin >> s;
  int in = 0;
  for(int k = 0; k < 4; ++k){
    if(k % 2 == 0) {
      for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
          if(A[i][j] == '.'){
            if(seen[i][j]){
              cout << "invalid grille" << endl;
              return 0;
            }
        
            ans[i][j] = s[in];
            ++in;
            seen[i][j] = true;
          }
        }
      }
      r(k);
    }
    else {
      for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
          if(B[i][j] == '.'){
            if(seen[i][j]){
              cout << "invalid grille" << endl;
              return 0;
            }
        
            ans[i][j] = s[in];
            ++in;
            seen[i][j] = true;
          }
        }
      }
      r(k); 
    }
  }
  if(in != n*n) { cout << "invalid grille" << endl; return 0; }
  
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      cout << ans[i][j];
  cout << endl;
}

