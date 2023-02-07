#include <bits/stdc++.h>
using namespace std;

int n, x, y, a, b, td;
int U, D, L, R;
string s;

bool check(int l) {
  if (td > (2*l) or (td - (2*l)) % 2) return false;

  int cx = a, cy = b;
  string t = s.substr(0, l);
  for (auto& c : t) {
    if (c == 'U') cy--;
    if (c == 'D') cy++;
    if (c == 'R') cx--;
    if (c == 'L') cx++;
  }

  int d = abs(cy-y) + abs(cx-x);
  if (d <= l and (d - l) % 2 == 0) return true;

  for (int i = 0; i+l+1 <= n; i++) {
    if (s[i] == 'U') cy++;
    if (s[i] == 'D') cy--;
    if (s[i] == 'R') cx++;
    if (s[i] == 'L') cx--;

    if (s[i+l] == 'U') cy--;
    if (s[i+l] == 'D') cy++;
    if (s[i+l] == 'R') cx--;
    if (s[i+l] == 'L') cx++;

    d = abs(cy-y) + abs(cx-x);

    if (d <= l and (d - l) % 2 == 0) return true;
  }
  return false;
}

int main() {
  cin >> n;
  cin >> s;
  cin >> x >> y;

  U = count(begin(s), end(s), 'U');
  D = count(begin(s), end(s), 'D');
  L = count(begin(s), end(s), 'L');
  R = count(begin(s), end(s), 'R');
  a = R - L;
  b = U - D;
  td = abs(b-y) + abs(a-x);

  if (!check(n)) {
    cout << -1 << '\n';
    return 0;
  }
  
  int l = 0, h = n;
  while ((h - l) > 4) {
    int m = (h + l) / 2;
    (check(m) ? h : l) = m;
  }

  while (!check(l) and l <= h) l++;
  cout << l << endl;
}