#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> A, S, T;

int main() {
  cin >> n;
  A.assign(n, 0);
  long long s = 0;
  for (auto& a : A) {
    cin >> a;
    s += a;
  }

  if (s % 3) {
    cout << 0 << '\n';
    return 0;
  }

  s = s / 3;
  long long t = 0;
  S.assign(n, 0);
  for (int i = 0; i < n-1; i++) {
    t += A[i];
    S[i+1] = t == s;
  }

  // for (int i = 0; i < n; i++) cout << S[i] << ' ';
  // cout << '\n';

  t = 0;
  long long c = 0;
  T.assign(n, 0);
  for (int i = n-1; i >= 0; i--) {
    t += A[i];
    T[i] = t == s;
    c += t == s;
  }

  // for (int i = 0; i < n; i++) cout << T[i] << ' ';
  // cout << '\n';

  s = 0;
  for (int i = 0; i < n; i++) {
    if (T[i]) c--;
    if (S[i]) s += c;
  }
  cout << s << '\n';
}