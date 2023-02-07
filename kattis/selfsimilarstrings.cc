#include <bits/stdc++.h>
using namespace std;

string s;

int main () {
  while (cin >> s) {
    int n = s.size();
    int ans = 0;

    for (int i = n; i > 0; i--) {
      bool q = true;
      for (int j = 0; j < (n - i) + 1; j++) {
        bool p = false;
        string t = s.substr(j, i);
        for (int k = 0; k < (n - i) + 1; k++) {
          if (j == k) continue;
          string u = s.substr(k, i);
          if (t == u) {
            p = true;
            break;
          }
        }
        if (!p) {
          q = false;
          break;
        }
      }
      if (q) {
        ans = i;
        break;
      }
    }
    cout << ans << '\n';
  }
}