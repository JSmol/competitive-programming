/*  zfunction longest common prefix of s[i..] and s[0..] for each i > 0 in O(n)
 *  example: zfunction("abacaba") => {0, 0, 1, 0, 3, 0, 1}
 */

vector<int> zfunction(string s) {
  int n = sz(s);
  vector<int> z(n, 0);
  int L = 0, R = 0;
  for (int i = 1; i < n; i++) {
    if (i > R) {
      L = R = i;
      while (R < n and s[R - L] == s[R]) R++;
      z[i] = R - L; R--;
    } else {
      int k = i-L;
      if (z[k] < R - i + 1) z[i] = z[k];
      else {
        L = i;
        while (R < n and s[R - L] == s[R]) R++;
        z[i] = R - L; R--;
      }
    }
  }
  return z;
}

