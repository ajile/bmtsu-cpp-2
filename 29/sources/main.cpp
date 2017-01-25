#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;


// ===================================================
// CNumber
// ===================================================
class CNumber {
  int number;
  public:
    CNumber (int);
    void print() { cout << "  My value is: " << number; };
    int get() { return number; };
};

CNumber::CNumber(int num) { number = num; }


// ===================================================
// Main
// ===================================================
int main(void) {
  CNumber * n1 = new CNumber(5);

  cout << "Dummy" << endl;

  return 0;
}
