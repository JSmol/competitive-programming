#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void solve(int n)
{
    cout << n << ' ';

    vector<int> devisors;
    devisors.push_back(1);

    int max = floor(sqrt(n))+1;
    for (int i = 2; i < max; i++) {
        if (n % i == 0) {
            devisors.push_back(i);
            if (i != n/i) devisors.push_back(n/i);
        }
    }

    int sum = 0;
    for (vector<int>::iterator it = devisors.begin(); it != devisors.end(); ++it) {
        sum += *it;
    }

    if (sum == n) cout << "perfect" << endl;
    else if (sum <= n+2 && sum >= n-2) cout << "almost perfect" << endl;
    else cout << "not perfect" << endl;
}

int main ()
{
    int n = 0;
    while (cin >> n)
    {
        solve(n);
    }

    return 0;
}
