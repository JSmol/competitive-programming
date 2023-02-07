#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> vars;

int main()
{
  string input;
  while (cin >> input) {
    if (input == "define") {
      int var;
      cin >> var;
      string name;
      cin >> name;

      vars[name] = var;

    } else {
      string lhs, rhs;
      char op;
      cin >> lhs >> op >> rhs;

      map<string, int>::iterator it;

      switch (op) {
        case '=':
          it = vars.find(lhs);
          if (it == vars.end()) {
            cout << "undefined" << endl;
            break;
          }
          it = vars.find(rhs);
          if (it == vars.end()) {
            cout << "undefined" << endl;
            break;
          }
          if (vars[lhs] == vars[rhs]) {
            cout << "true" << endl;
            break;
          } else {
            cout << "false" << endl;
            break;
          }

        case '<':
          it = vars.find(lhs);
          if (it == vars.end()) {
            cout << "undefined" << endl;
            break;
          }
          it = vars.find(rhs);
          if (it == vars.end()) {
            cout << "undefined" << endl;
            break;
          }
          if (vars[lhs] < vars[rhs]) {
            cout << "true" << endl;
            break;
          } else {
            cout << "false" << endl;
            break;
          }
        case '>':
          it = vars.find(lhs);
          if (it == vars.end()) {
            cout << "undefined" << endl;
            break;
          }
          it = vars.find(rhs);
          if (it == vars.end()) {
            cout << "undefined" << endl;
            break;
          }
          if (vars[lhs] > vars[rhs]) {
            cout << "true" << endl;
            break;
          } else {
            cout << "false" << endl;
            break;
          }
      }
    }
  }
}
