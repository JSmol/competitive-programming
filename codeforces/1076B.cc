#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
}

typedef long long ll;
ll n;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
 
  
  ll i = 2;
  while (n % i != 0 and i * i <= n+1) i++;
  
  if (i*i > n+1)
    cout << 1 << endl;
  else {
    if (n % 2 == 0)
      cout << (n / i) << endl;
    else {
      n -= i;
      cout << 1 + (n / 2) << endl;
    }
  }
}

