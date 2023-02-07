#include <bits/stdc++.h>
using namespace std;

set<long long> S;

int main() {
  long long n;
  cin >> n;
  S.insert(n);

  long long i = 1;
  while (i * i <= n) {
    if (n % i == 0 and S.count(i) == 0) {
      S.insert(i); 
      S.insert(n / i); 
    }
    i++;
  }

  cout << S.size() << endl;
}