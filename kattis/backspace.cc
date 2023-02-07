#include <iostream>
#include <string>
using namespace std;

int main()
{
  char c;
  string s;
  while(cin >> c) {
    if (c != '<') {
        s.push_back(c);
    } else {
      s.pop_back();
    }
  }
  cout << s;
}


