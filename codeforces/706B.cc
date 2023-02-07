#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int> A;

int main() {
  cin >> n;
  A.assign(n, 0);
  for (auto& a : A) cin >> a;
  sort(begin(A), end(A));

  cin >> q;
  for (int i = 0; i < q; i++) {
    int a;
    cin >> a;
    cout << (upper_bound(begin(A), end(A), a) - A.begin()) << '\n';
  }
}