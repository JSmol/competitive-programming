#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
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

int A[4], ans[7], V[6] = {4, 8, 16, 15, 23, 42};

void f(int a, int b, int i) {
  if (a == 32 and b == 128) { ans[i] = 4; ans[i+1] = 8; ans[i+2] = 16; }
  if (a == 64 and b == 128) { ans[i] = 4; ans[i+1] = 16; ans[i+2] = 8; }
  if (a == 32 and b == 64) { ans[i] = 8; ans[i+1] = 4; ans[i+2] = 16; }
  if (a == 128 and b == 64) { ans[i] = 8; ans[i+1] = 16; ans[i+2] = 4; }
  if (a == 64 and b == 32) { ans[i] = 16; ans[i+1] = 4; ans[i+2] = 8; }
  if (a == 128 and b == 32) { ans[i] = 16; ans[i+1] = 8; ans[i+2] = 4; }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cout << "? 1 2" << endl;
  cout << "? 2 3" << endl;
  cout << "? 4 5" << endl;
  cout << "? 5 6" << endl;

  for (int i = 0; i < 4; i++) cin >> A[i];

  for (int i = 3; i < 6; i++) {
    if (A[0] % V[i] == 0 and A[1] % V[i] == 0) {
      ans[2] = V[i];
      ans[1] = A[0]/ans[2];
      ans[3] = A[1]/ans[2];
    }

    if (A[0] % V[i] == 0 and A[1] % V[i] != 0) {
      ans[1] = V[i];
      ans[2] = A[0]/ans[1];
      ans[3] = A[1]/ans[2];
    }

    if (A[0] % V[i] != 0 and A[1] % V[i] == 0) {
      ans[3] = V[i];
      ans[2] = A[1]/ans[3];
      ans[1] = A[0]/ans[2];
    }
  }

  for (int i = 3; i < 6; i++) {
    if (A[2] % V[i] == 0 and A[3] % V[i] == 0) {
      ans[5] = V[i];
      ans[4] = A[2]/ans[5];
      ans[6] = A[3]/ans[5];
    }

    if (A[2] % V[i] == 0 and A[3] % V[i] != 0) {
      ans[4] = V[i];
      ans[5] = A[2]/ans[4];
      ans[6] = A[3]/ans[5];
    }

    if (A[2] % V[i] != 0 and A[3] % V[i] == 0) {
      ans[6] = V[i];
      ans[5] = A[3]/ans[6];
      ans[4] = A[2]/ans[5];
    }
  }

  if (ans[1] == 0) f(A[0], A[1], 1);
  if (ans[4] == 0) f(A[2], A[3], 4);

  cout << "! ";
  for (int i = 1; i <= 6; i++) cout << ans[i] << ' ';
  cout << endl;
}

