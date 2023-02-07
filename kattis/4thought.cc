#include <iostream>
#include <string>
#include <map>
using namespace std;

map<int, string> solutions;

void solve(int n)
{
    if (solutions.find(n) != solutions.end())
        cout << solutions[n] << " = " << n << endl;
    else
        cout << "no solution" << endl;
}

int main ()
{
    solutions[4 + 4 + 4 + 4] = "4 + 4 + 4 + 4";
    solutions[4 + 4 + 4 - 4] = "4 + 4 + 4 - 4";
    solutions[4 + 4 + 4 / 4] = "4 + 4 + 4 / 4";
    solutions[4 + 4 + 4 * 4] = "4 + 4 + 4 * 4";
    solutions[4 + 4 - 4 + 4] = "4 + 4 - 4 + 4";
    solutions[4 + 4 - 4 - 4] = "4 + 4 - 4 - 4";
    solutions[4 + 4 - 4 / 4] = "4 + 4 - 4 / 4";
    solutions[4 + 4 - 4 * 4] = "4 + 4 - 4 * 4";
    solutions[4 + 4 / 4 + 4] = "4 + 4 / 4 + 4";
    solutions[4 + 4 / 4 - 4] = "4 + 4 / 4 - 4";
    solutions[4 + 4 / 4 / 4] = "4 + 4 / 4 / 4";
    solutions[4 + 4 / 4 * 4] = "4 + 4 / 4 * 4";
    solutions[4 + 4 * 4 + 4] = "4 + 4 * 4 + 4";
    solutions[4 + 4 * 4 - 4] = "4 + 4 * 4 - 4";
    solutions[4 + 4 * 4 / 4] = "4 + 4 * 4 / 4";
    solutions[4 + 4 * 4 * 4] = "4 + 4 * 4 * 4";
    solutions[4 - 4 + 4 + 4] = "4 - 4 + 4 + 4";
    solutions[4 - 4 + 4 - 4] = "4 - 4 + 4 - 4";
    solutions[4 - 4 + 4 / 4] = "4 - 4 + 4 / 4";
    solutions[4 - 4 + 4 * 4] = "4 - 4 + 4 * 4";
    solutions[4 - 4 - 4 + 4] = "4 - 4 - 4 + 4";
    solutions[4 - 4 - 4 - 4] = "4 - 4 - 4 - 4";
    solutions[4 - 4 - 4 / 4] = "4 - 4 - 4 / 4";
    solutions[4 - 4 - 4 * 4] = "4 - 4 - 4 * 4";
    solutions[4 - 4 / 4 + 4] = "4 - 4 / 4 + 4";
    solutions[4 - 4 / 4 - 4] = "4 - 4 / 4 - 4";
    solutions[4 - 4 / 4 / 4] = "4 - 4 / 4 / 4";
    solutions[4 - 4 / 4 * 4] = "4 - 4 / 4 * 4";
    solutions[4 - 4 * 4 + 4] = "4 - 4 * 4 + 4";
    solutions[4 - 4 * 4 - 4] = "4 - 4 * 4 - 4";
    solutions[4 - 4 * 4 / 4] = "4 - 4 * 4 / 4";
    solutions[4 - 4 * 4 * 4] = "4 - 4 * 4 * 4";
    solutions[4 / 4 + 4 + 4] = "4 / 4 + 4 + 4";
    solutions[4 / 4 + 4 - 4] = "4 / 4 + 4 - 4";
    solutions[4 / 4 + 4 / 4] = "4 / 4 + 4 / 4";
    solutions[4 / 4 + 4 * 4] = "4 / 4 + 4 * 4";
    solutions[4 / 4 - 4 + 4] = "4 / 4 - 4 + 4";
    solutions[4 / 4 - 4 - 4] = "4 / 4 - 4 - 4";
    solutions[4 / 4 - 4 / 4] = "4 / 4 - 4 / 4";
    solutions[4 / 4 - 4 * 4] = "4 / 4 - 4 * 4";
    solutions[4 / 4 / 4 + 4] = "4 / 4 / 4 + 4";
    solutions[4 / 4 / 4 - 4] = "4 / 4 / 4 - 4";
    solutions[4 / 4 / 4 / 4] = "4 / 4 / 4 / 4";
    solutions[4 / 4 / 4 * 4] = "4 / 4 / 4 * 4";
    solutions[4 / 4 * 4 + 4] = "4 / 4 * 4 + 4";
    solutions[4 / 4 * 4 - 4] = "4 / 4 * 4 - 4";
    solutions[4 / 4 * 4 / 4] = "4 / 4 * 4 / 4";
    solutions[4 / 4 * 4 * 4] = "4 / 4 * 4 * 4";
    solutions[4 * 4 + 4 + 4] = "4 * 4 + 4 + 4";
    solutions[4 * 4 + 4 - 4] = "4 * 4 + 4 - 4";
    solutions[4 * 4 + 4 / 4] = "4 * 4 + 4 / 4";
    solutions[4 * 4 + 4 * 4] = "4 * 4 + 4 * 4";
    solutions[4 * 4 - 4 + 4] = "4 * 4 - 4 + 4";
    solutions[4 * 4 - 4 - 4] = "4 * 4 - 4 - 4";
    solutions[4 * 4 - 4 / 4] = "4 * 4 - 4 / 4";
    solutions[4 * 4 - 4 * 4] = "4 * 4 - 4 * 4";
    solutions[4 * 4 / 4 + 4] = "4 * 4 / 4 + 4";
    solutions[4 * 4 / 4 - 4] = "4 * 4 / 4 - 4";
    solutions[4 * 4 / 4 / 4] = "4 * 4 / 4 / 4";
    solutions[4 * 4 / 4 * 4] = "4 * 4 / 4 * 4";
    solutions[4 * 4 * 4 + 4] = "4 * 4 * 4 + 4";
    solutions[4 * 4 * 4 - 4] = "4 * 4 * 4 - 4";
    solutions[4 * 4 * 4 / 4] = "4 * 4 * 4 / 4";
    solutions[4 * 4 * 4 * 4] = "4 * 4 * 4 * 4";

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i)
    {
        int n;
        cin >> n;
        solve(n);
    }

    return 0;
}
