#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main ()
{

    vector<string> lines;
    string current_line;
    int longest_line_length = 0;
    int raggedness = 0;

    while (getline(cin, current_line))
    {
        int current_line_length = current_line.length();

        if (current_line_length > longest_line_length)
            longest_line_length = current_line_length;

        lines.push_back(current_line);

    }

    lines.pop_back();
    int num_lines = lines.size();

    for (int i = 0; i < num_lines; ++i)
    {
        current_line = lines.back();
        lines.pop_back();
        if (current_line.length() == longest_line_length)
            continue;
        
        raggedness += (longest_line_length - current_line.length()) * (longest_line_length - current_line.length());
    }

    cout << raggedness << endl;

    return 0;
}

