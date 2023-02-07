#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
}

int n;
vector<int> A;
stack<int> ans;
int B[200002][5];

int f(int i, int k) {
  if (i == n-1) {
    ans.push(k);
    return true;
  }

  int& x = B[i][k];
  if (x != -1) return x;

  x = false;
  if (A[i] < A[i+1]) {
    for (int j = k+1; j < 5; j++) {
      x = f(i+1, j);

      if (x) {
        ans.push(k);
        break;
      }
    }
  }

  if (A[i] > A[i+1]) {
    for (int j = k-1; j >= 0; j--) {
      x = f(i+1, j);

      if (x) {
        ans.push(k);
        break;
      }
    }
  }

  if (A[i] == A[i+1]) {
    for (int j = 0; j < 5; j++) {
      if (j != k) 
        x = f(i+1, j);
      
      if (x) {
        ans.push(k);
        break;
      }
    }
  }

  return x;
} 

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  A.assign(n, 0);
  for (auto& a : A) cin >> a;

  for (int i = 0; i < 200002; i++)
    fill(B[i], B[i]+5, -1);

  for (int i = 0; i < 5; i++) {
    if (f(0, i))
      break;
  }

  if (ans.empty()) {
    cout << -1 << endl;
    return 0;
  }

  while (!ans.empty()) 
    cout << ans.top()+1 << ' ',
    ans.pop();
  cout << endl;
}

