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

int r, c;
char A[101][101];

bool bounds(int i, int j) {
   return i >= 0 && i < r && j >= 0 && j < c;
}

vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int bfs_interior(pair<int, int> S) {
   queue<pair<int, int>> Q;
   Q.push(S);
   //set<pair<int, int>> seen;
   bool seen[101][101] = {0};
   int s = 0;
   while (!Q.empty()) {
      auto n = Q.front(); Q.pop();
      //seen.insert(n);
      if (seen[n.fst][n.snd]) continue;
      seen[n.fst][n.snd] = true;
      assert(A[n.fst][n.snd] == '.');
      s++;
      for (auto m : moves) {
	 auto pos = make_pair(n.fst + m.fst, n.snd + m.snd);
	 if (!seen[pos.fst][pos.snd] && bounds(pos.fst, pos.snd) && A[pos.fst][pos.snd] == '.') {
	    Q.push(pos);
	 }
      }
   }
   return s;
}

bool exterior(pair<int, int> S) {
   queue<pair<int, int>> Q;
   Q.push(S);
   //set<pair<int, int>> seen;
   bool seen[101][101] = {0};
   int s = 0;
   while (!Q.empty()) {
      auto n = Q.front(); Q.pop();
      //seen.insert(n);
      if (seen[n.fst][n.snd]) continue;
      seen[n.fst][n.snd] = true;
      assert(A[n.fst][n.snd] == '.');
      s++;
      for (auto m : moves) {
	 auto pos = make_pair(n.fst + m.fst, n.snd + m.snd);
	 if (!seen[pos.fst][pos.snd]) {
	    if(!bounds(pos.fst, pos.snd)) return true;
	    if (A[pos.fst][pos.snd] == '.')
	       Q.push(pos);
	 }
      }
   }
   return false;
}

bool surrounded(int i, int j) {
   return A[i][j]== 'X' && i > 0 && A[i-1][j] == 'X' && i < r-1 && A[i+1][j] == 'X' && j > 0
      && A[i][j-1] == 'X' && j < c-1 && A[i][j+1] == 'X';
}



bool loop_is_A(pair<int, int> S, pair<int, int> T) {
   queue<pair<int, int>> Q;
   Q.push(S);
   set<pair<int, int>> seen;
   seen.insert(T);
   while (!Q.empty()) {
      auto n = Q.front(); Q.pop();
      seen.insert(n);

      for (auto m: moves) {
	 auto pos = make_pair(n.fst + m.fst, n.snd + m.snd);
	 
	 if (seen.find(pos) != seen.end()) continue;
	 
	 if (bounds(pos.fst, pos.snd)) {
	    if (A[pos.fst][pos.snd] == 'A') return true;
	    else if (A[pos.fst][pos.snd] == 'B') return false;
	    
	    else if (A[pos.fst][pos.snd] == 'X') {
	       if (surrounded(pos.fst, pos.snd)) { // next is intersection, move through it
		  //Q.push(pos);
		  seen.insert(pos);
		  Q.emplace(pos.fst + m.fst, pos.snd + m.snd); // add same move to it again
	       }
	       else {
		  Q.push(pos);
	       }
	    }
	 }
      }
   }
   assert(false);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> r >> c;
  for (int i = 0; i < r; i++) cin >> A[i];

/*  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++)
      cout << A[i][j] << ' ';
    cout << endl;
    }*/

  vector<pair<int, int>> isect;

  for (int i = 0; i < r; i++) {
     for (int j = 0; j < c; j++) {
	if (A[i][j]== 'X' && i > 0 && A[i-1][j] == 'X' && i < r-1 && A[i+1][j] == 'X' && j > 0 && A[i][j-1] == 'X' && j < c-1
	        && A[i][j+1] == 'X') {
	   isect.emplace_back(i, j);
	}
     }
  }
  
  pair<int, int> S = make_pair(isect[0].fst + 1, isect[0].snd); // up/down
  pair<int, int> R = make_pair(isect[0].fst, isect[0].snd + 1); // left/right
  pair<int, int> T = isect[0];

  bool ud_is_A = loop_is_A(S, T);

  int re, ce;
  for (int i: {-1, 1}) {
     for (int j: {-1, 1}) {
	if (exterior({T.fst + i, T.snd + j})) {
	   re = i;
	   ce = j;
	}
     }
  }

  int Aa, Ba, Ia;
  Ia = bfs_interior({T.fst + -1*re, T.snd -1*ce});
  if (ud_is_A) {
     Aa = bfs_interior({T.fst + re, T.snd + -1*ce});
     Ba = bfs_interior({T.fst + -1*re, T.snd + ce});
  } else {
     Aa = bfs_interior({T.fst + -1*re, T.snd + ce});
     Ba = bfs_interior({T.fst + re, T.snd + -1*ce});
  }

  cout << Aa << ' ' << Ba << ' ' << Ia << endl;
}

