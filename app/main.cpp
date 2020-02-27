#include "add.h"

int main() {
  Money c1(1, 60000), c2, c3, c4(600, 200), c5, c6(-5, 10), c7(1, 90), c8, c9;
  c2 = c1;
  c3 = c2 - c4;
  c5 = c6 / 0;

  cout << c1 << endl;
  cout << c2 << endl;
  cout << c3 << endl;
  cout << c5 << endl;
  if (c1 > c4)
  {
    cout << "Lox" << endl;
  }
  if (c1 < c4)
  {
    cout << "Krasava" << endl;
  }
  else {
    cout << "polni lox" << endl;
  }
  if (c8 == c9) {

    cout << "you gay" << endl;
  }

  Money* pc1 = new Money(c1);
  delete pc1;


  getchar();
  getchar();
  return 0;
}