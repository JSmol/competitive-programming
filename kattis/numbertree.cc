#include <iostream>
#include <string>
using namespace std;

int n;

int main ()
{
  cin >> n;
  int value = (2 << n) - 1;

  string s;
  cin >> s;

  int subtract = 1;
  char p = 'L';

  for (int i = 0; i < s.length(); i++) {
    // cout << value << endl;
    // cout << subtract << endl;
    if (s[i] == 'L' && p == 'L') {
      value -= subtract;
      subtract = subtract << 1;

    } else if (s[i] == 'L' && p != 'L') {
      subtract--;
      value -= subtract;
      subtract = subtract << 1;

    } else if (s[i] == 'R' && p == 'R') {
      value -= subtract;
      subtract = subtract << 1;
        
    } else if (s[i] == 'R' && p != 'R') {
      subtract++;
      value -= subtract;
      subtract = subtract << 1;

    }
    
    p = s[i];
  }

  cout << value << endl;
  
}
