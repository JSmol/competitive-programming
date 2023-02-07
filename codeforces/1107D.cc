#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << p.fst << ' ' << p.snd; return o;
}

int A[5555][5555];
int S[5555][5555];
int n;
string x;

int h(char x) {
  return x <= '9' ? x - '0' : x - 'A' + 10;
}

int f(int i, int j, int b) {
  if (i-b >= 0 and j-b >= 0)
    return S[i][j] - S[i-b][j] - S[i][j-b] + S[i-b][j-b];
  if (i-b >= 0)
    return S[i][j] - S[i-b][j];
  if (j-b >= 0)
    return S[i][j] - S[i][j-b];

  return S[i][j];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    for (int j = 0; j < n/4; j++) {
      int m = h(x[j]);
      for (int k = 0; k < 4; k++)
        A[i][j*4+k] = m & (8 >> k) ? 1 : 0;
    }
  }

  for (int i = 0, s = 0, t = 0; i < n; i++)
    s += A[i][0], t += A[0][i], S[i][0] = s, S[0][i] = t; 

  for (int i = 1; i < n; i++)
    for (int j = 1; j < n; j++)
      S[i][j] = A[i][j] + S[i-1][j] + S[i][j-1] - S[i-1][j-1];

  for (int i = n; i >= 1; i--) {
    if (n % i == 0) {
      for (int j = i-1; j < n; j+=i) 
        for (int k = i-1; k < n; k+=i) 
          if (f(j, k, i) != 0 and f(j, k, i) != i*i) 
            goto next; 
      cout << i << endl;
      break;
    }
next: ;
  }
}

