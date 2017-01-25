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
// CRecord
// ===================================================
class CRecord {
  CNumber * number;
  CNumber * number_array;
  int size;
  public:
    CNumber * min = NULL;
    CNumber * max = NULL;
    CRecord (CNumber *, CNumber *, int);
    int get() { return number -> get(); };
    CNumber * getMin() { return number; }; // @todo
    CNumber * getMax() { return number; }; // @todo
    void print() {
      cout << "  number: ";
      number -> print();
      cout << endl;
      for (int i = 0; i < size; i++) {
        cout << "  Element #" << i << ": ";
        number_array[i].print();
        cout << endl;
      }
    };
    void sort_and_determine() {

      for (int i = 0; i < size; i++) {
        CNumber * fi = &number_array[i];
        for (int j = 0; j < size; j++) {
          CNumber * fj = &number_array[j];
          /* cout << "i:" << fi -> get() << " > j:" << fj -> get() << " === "; */
          if (fi -> get() < fj -> get()) {
            /* cout << "SWAP"; */
            /* cout << "[" << number_array[i].get() << " && " << number_array[j].get() << "]"; */
            CNumber * tmp = (CNumber*)malloc(sizeof(CNumber*));
            *tmp = number_array[i];
            number_array[i] = number_array[j];
            number_array[j] = *tmp;
            /* cout << "[" << number_array[i].get() << " && " << number_array[j].get() << "]"; */
          }
          /* cout << endl; */
        }
        if (min == NULL || fi -> get() < min -> get()) { min = fi; }
        if (max == NULL || fi -> get() > max -> get()) { max = fi; }
      }
    };
};

CRecord::CRecord(CNumber * num, CNumber * nums, int s) {
  number = num;
  number_array = nums;
  size = s;
}


// ===================================================
// Main
// ===================================================
int main(void) {
  CNumber * n1 = new CNumber(5);
  CNumber * n2 = new CNumber(2);
  CNumber * n3 = new CNumber(9);

  /* CNumber * arr = (CNumber *)malloc(sizeof(CNumber) * 3); */
  CNumber arr[3] = { *n1, *n2, *n3 };

  cout << "# CNumber.print():" << endl;
  n1 -> print();
  cout << endl;
  cout << endl;

  cout << "# CNumber.get():" << n1 -> get() << endl;


  CRecord r1 (n1, arr, sizeof(arr) / sizeof(*arr));

  cout << "# ORIGIN" << endl;
  cout << "# CRecord.print():" << endl;
  r1.print();
  cout << endl;

  cout << "# CRecord.get():" << r1.get() << endl;

  cout << "# CRecord.sort():" << endl;

  r1.sort_and_determine();

  cout << endl;
  cout << endl;
  cout << "# SORTED" << endl;
  cout << "# CRecord.print():" << endl;
  r1.print();
  cout << endl;
  cout << "# CRecord.min(): " << (r1.min -> get()) << endl;
  cout << "# CRecord.max(): " << (r1.max -> get()) << endl;

  return 0;
}
