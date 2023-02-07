#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
  cin >> n;
  cin >> s;

  char p = s[0];
  for (int i = 1; i < n; i++) {
    if (p != s[i]) {
      cout << "YES" << '\n';
      cout << p << s[i] << '\n';
      return 0;
    }
    p = s[i];
  }
  cout << "NO" << '\n';
}