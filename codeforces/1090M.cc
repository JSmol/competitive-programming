#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define get(t, i) get<(i)>((t))
#define fst first
#define snd second

int n, k;
vector<int> A;

int main() {
  cin >> n >> k;
  A.assign(n, 0);
  for (auto& a : A) cin >> a;

  int ans = 0;
  for (int i = 0, j = 0; i < n; i = j) {
    j = i + 1;
    while (A[j-1] != A[j]) j++;
    ans = max(ans, j - i);
  }

  cout << ans << endl;
}

