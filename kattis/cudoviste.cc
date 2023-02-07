#include <iostream>
using namespace std;

int main()
{
    char lot[51][51];

    int R, C;
    cin >> R >> C;

    for (int row = 1; row <= R; row++)
    {
        for (int col = 1; col <= C; col++)
        {
            cin >> lot[row][col];
        }
    }

    for (int cars_to_squash = 0; cars_to_squash <= 4; cars_to_squash++)
    {
        int avail_spaces = 0;

        for (int row = 1; row < R; row++)
        {
            for (int col = 1; col < C; col++)
            {
                if (lot[row][col]     == '#' ||
                    lot[row+1][col]   == '#' ||
                    lot[row][col+1]   == '#' ||
                    lot[row+1][col+1] == '#') continue;

                int cars_squashed = 0;

                if (lot[row][col] == 'X') cars_squashed += 1;
                if (lot[row+1][col] == 'X') cars_squashed += 1;
                if (lot[row][col+1] == 'X') cars_squashed += 1;
                if (lot[row+1][col+1] == 'X') cars_squashed += 1;

                if (cars_squashed == cars_to_squash) avail_spaces += 1;
            }
        }
        cout << avail_spaces << endl;
    }

    return 0;
}


