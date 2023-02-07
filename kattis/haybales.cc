#include <iostream>
using namespace std;

int main ()
{
  string input;
  cin >> input;

  int k = 0;
  bool done = false;

  while (!done) {
    done = true;
    auto it = input.find("PPC");
    if (it != string::npos) {
      input[it] = 'C';
      input[it+1] = 'P';
      input[it+2] = 'P';
      k++;
      done = false;
      continue;
    }
    it = input.find("PCC");
    if (it != string::npos) {
      input[it] = 'C';
      input[it+1] = 'C';
      input[it+2] = 'P';
      k++;
      done = false;
      continue;
    }
    it = input.find("CPC");
    if (it != string::npos) {
      input[it] = 'C';
      input[it+1] = 'C';
      input[it+2] = 'P';
      k++;
      done = false;
      continue;
    }
    it = input.find("PCP");
    if (it != string::npos) {
      input[it] = 'C';
      input[it+1] = 'P';
      input[it+2] = 'P';
      k++;
      done = false;
      continue;
    }
  }

  cout << k << endl;

}
