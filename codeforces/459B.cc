#include <bits/stdc++.h>
using namespace std;

long long n;
vector<int> A;

int main() {
  cin >> n;
  A.assign(n, 0);
  for (auto& a : A) cin >> a;
  sort(begin(A), end(A));

  long long i = 0, j = n-1;
  long long d = A[j] - A[i];
  if (d == 0) {
    cout << d << ' ' << ((n * (n-1)) / 2) << '\n';
    return 0;
  }

  while (i < n and A[0] == A[i]) i++;
  while (j >= 0 and A[j] == A[n-1]) j--;
  
  j = (n-1) - j;
  long long ans = i * j;
  cout << d << ' ' << ans << '\n';
}