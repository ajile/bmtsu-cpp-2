#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int pow(int num, int deg) {
  if (deg == 0) return 1;
  int orig = num;
  for (int i = 1; i < deg; i++) {
    num *= orig;
  }
  return num;
}

int get_number(int m) {
  vector<int> a;
  int position = 0;
  cout << "Given number: ";
  while (m != 0) {
    /* cout << (m % 2); */
    // Devision by 2
    /* cout << (m ? pow(2, position) : 0) << endl; */
    a.push_back(m % 2);
    /* cout << m << endl; */
    m = m >> 1;
    position++;
  }

  for (int i = a.size() - 1; i >= 0; i--) {
    cout << a[i];
  }
  cout << endl;

  int num = 0;
  cout << "Opposite number: ";
  for (int i = 0; i < a.size(); ++i) {
    cout << a[i];
    if (a[i] == 1) {
      /* cout << "===" << i << "[" << pow(2, i-1) << "]" << endl; */
      /* cout << "===" << (a.size() - i - 1) << "[" << pow(2, a.size() - i - 1) << "]" << endl; */
      num += pow(2, a.size() - i - 1);
    }
  }
  cout << endl;
  return num;
}

int main(void) {
  int m = 9;

  cout << "Opposite number is " << get_number(m);
  return 0;
}
