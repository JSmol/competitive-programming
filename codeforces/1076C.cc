#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
}

double d, t;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  std::cout << std::fixed << std::showpoint;
  std::cout << std::setprecision(10);
  cin >> t;
  while (t--) {
    cin >> d;
    double r = d * d - 4 * d;

    if (r < 0) {
      cout << 'N' << '\n';
    } else {
      cout << 'Y' << ' ' << ((d + sqrt(r)) / 2) << ' ' << ((d - sqrt(r)) / 2) << '\n';
    }
  }
}

