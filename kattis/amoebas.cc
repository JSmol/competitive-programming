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


char C[104][104];
bool D[104][104] = {false};
int m, n;

void DFS(int i, int j){
  if(i >= m || i < 0 || j >= n || j < 0) return;
  if(!D[i][j] && C[i][j] == '#'){
    D[i][j] = true;
    for(int k : {-1, 0, 1}){
      for(int l : {-1, 0, 1}){
        DFS(i+k,j+l);
      }
    }
  }
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  cin >> m >> n;
  for(int i = 0; i < m; ++i){
    cin >> C[i];
  }
  int ans = 0;
  for(int i = 0; i < m; ++i){
    for(int j = 0; j < n; ++j){
      if(C[i][j] == '#' && !D[i][j]){
        
       
        DFS(i,j);
        ++ans;
      }
    } 
  }
  cout << ans << endl;
}

