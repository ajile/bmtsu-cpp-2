#include <iostream>
#include <stdio.h>

using namespace std;

int main(void) {
  int base1 = 10000;
  int base2 = 100;
  int int1 = 81;
  int int2 = 73;
  int int3 = 92;
  int intr = 0;

  // int1 is the biggest
  if (int1 > int2 && int1 > int3) {
    intr = int1 * base1 + (int2 > int3 ? int2 * base2 + int3 : int3 * base2 + int2);
  }

  // int2 is the biggest
  if (int2 > int1 && int2 > int3) {
    intr = int2 * base1 + (int1 > int3 ? int1 * base2 + int3 : int3 * base2 + int1);
  }

  // int3 is the biggest
  if (int3 > int2 && int3 > int1) {
    intr = int3 * base1 + (int1 > int2 ? int1 * base2 + int2 : int2 * base2 + int1);
  }

  cout << intr << endl;

  return 0;
}
