#include <iostream>
#include <stdio.h>

using namespace std;

int main(void) {
  int matrix[3][4] = {
    {-1,  5, -3,  2},
    {-7, -2, -2,  4},
    {-6,  9,  1, -8}
  };
  int newMatrix[2][4];
  int unsigned last = 4;
  int unsigned counter;
  int unsigned row;

  cout << "# The origin matrix:" << endl;
  for (int i = 0; i < sizeof(matrix) / sizeof(*matrix); ++i) {
    unsigned int line_length = sizeof(matrix[i]) / sizeof(*matrix[i]);
    for (int j = 0; j < line_length; ++j) {
      cout << matrix[i][j] << "; ";
    }
    cout << endl;
  }

  for (int i = 0; i < sizeof(matrix) / sizeof(*matrix); ++i) {
    counter = 0;
    for (int j = 0; j < sizeof(matrix[i]) / sizeof(*matrix[i]); ++j) {
      if (matrix[i][j] > 0) { counter++; }
    }

    if (counter <= last) {
      last = counter;
      row = i;
    }
  }

  cout << endl;

  cout << "# The row number " << row << " will be removed" << endl;

  cout << endl;

  int shift = 0;

  cout << "# Deleting:" << endl;
  for (int i = 0; i < sizeof(matrix) / sizeof(*matrix); ++i) {
    unsigned int line_length = sizeof(matrix[i]) / sizeof(*matrix[i]);
    if (row == i) {
      for (int j = 0; j < line_length; ++j) {
        cout << "Deleting address: " << (matrix[i] + j) << endl;
      }
      shift++;
      continue;
    }
    for (int j = 0; j < line_length; ++j) {
      newMatrix[i-shift][j] = matrix[i][j];
    }
  }

  cout << endl;

  cout << "# The resultee matrix:" << endl;
  for (int i = 0; i < sizeof(newMatrix) / sizeof(*newMatrix); ++i) {
    unsigned int line_length = sizeof(newMatrix[i]) / sizeof(*newMatrix[i]);
    for (int j = 0; j < line_length; ++j) {
      newMatrix[i][j] = newMatrix[i][j];
      cout << newMatrix[i][j] << "; ";
    }
    cout << endl;
  }

  return 0;
}
