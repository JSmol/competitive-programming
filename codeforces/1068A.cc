#include <bits/stdc++.h>
using namespace std;

long long n, m, k, l;

int main() {
  cin >> n >> m >> k >> l;
  l += k;
  
  long long req = (l+(m-1)) / m;
  if ((req * m) <= n) cout << req << endl;
  else cout << -1 << endl;
}