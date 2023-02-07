#include <iostream>
using namespace std;

int main ()
{
    int h, w, n;
    cin >> h >> w >> n;

    int bricks[10000];
    for (int i = 0; i < n; ++i)
        cin >> bricks[i];

    int current_width = 0;
    int current_height = 0;
    for (int i = 0; i < n; ++i)
    {

        current_width += bricks[i];

        if (current_width == w)
        {
            current_height += 1;
            current_width = 0;
        }
        if (current_width > w)
        {
            cout << "NO" << endl;
            break;
        }
        if (current_height == h)
        {
            cout << "YES" << endl;
            break;
        }
    }

    return 0;
}
