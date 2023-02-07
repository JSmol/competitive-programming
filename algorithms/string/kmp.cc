/*  KMP string matching O(n)
 *  pi[x] = length of longest commont prefix of s that is also a (proper) suffix
 *  calc_pi("alabala") => {-1, 0, 0, 1, 0, 1, 2, 3}
 *  match("atoat", "atoatoat") => {4, 7}
 */

vector<int> calc_pi(string s) {
  int n = sz(s);
  vector<int> pi(n + 1, -1);
  for (int i = 0; i < n; ++i) {
    int j = pi[i]; while (j != -1 and s[j] != s[i]) j = pi[j];
    pi[i + 1] = j + 1;
  }
  return pi;
}

vector<int> match(string text, string pat) {
  vector<int> pi = calc_pi(pat), ret; int j = 0;
  for (int i = 0; i < sz(text); ++i) {
    while (j != -1 and pat[j] != text[i]) j = pi[j];
    if (++j == sz(pat)) ret.push_back(i), j = pi[j];
  }
  return ret;
}
