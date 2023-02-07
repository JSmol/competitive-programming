#include <iostream>
#include <algorithm>
using namespace std;

int meals = 0, maxcap = 0;
int mealval[100] = {0};
int visited[100][100][3]; // [meal][cals][lasteat]
int best = 0;

int calcap (int r)
{
  int ret = maxcap;
  for (int i = 0; i < r; i++) {
    ret = (ret * 2) / 3;
  }
  return ret; 
}

void compute (int meal, int r, int currcal, int lasteat)
{
  int nextr;
  if (meal == meals) {
    if (currcal > best) {
      best = currcal;
    }
    return;
  }

  if (meal > meals) return;

  if (visited[meal][r][lasteat] < currcal) visited[meal][r][lasteat] = currcal;
  else return; 

  compute(meal+1, r+1,  currcal + min(calcap(r), mealval[meal]), 0);

  if (lasteat == 0) nextr = max(0, r-1);
  else nextr = 0;

  compute(meal+1, nextr,    currcal, lasteat+1);
}

int main ()
{
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      for (int k = 0; k < 3; k++) {
        visited[i][j][k] = -1;
      }
    }
  }

  cin >> meals >> maxcap;

  for (int i = 0; i < meals; i++) {
    cin >> mealval[i];
  }

  compute(0, 0, 0, 0);
  cout << best << endl;
}
