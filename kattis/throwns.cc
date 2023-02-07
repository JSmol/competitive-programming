#include <iostream>
#include <stack>
using namespace std;

int main ()
{
  stack<int> history;

  int n, k;
  cin >> n >> k;

  int cur, last = 0;
  history.push(0);

  for (int i = 0; i < k; i++) {
    string input;
    cin >> input;
    if (input == "undo") {
      int r;
      cin >> r;

      for (int i = 0; i < r; i++) history.pop();
      last = history.top();
      
    } else {
      int num = stoi(input);

      cur = ((((last + num) % n) +n) % n);
      last = cur;

      history.push(last);
    }
  }

  cout << history.top() << endl;
  return 0;
}
