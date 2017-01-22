#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int main(void) {

  FILE * F;

  // Filling F file by real numbers
  F = fopen("./sources/F.txt", "w");
  float numbers[] = { 3.1415926535, 2.7182818284, 6, 1, 2, 3, 0.5, -2, -1, -5, -2, -20, -1, -7, -8, -9, -11, -14 };
  int length = sizeof(numbers) / sizeof(numbers[0]);
  fwrite(numbers, sizeof(float), length, F);
  fclose(F);

  // Reading F file consist of real numbers
  F = fopen("./sources/F.txt", "r");

  float minOdd, min = NULL, max = NULL, first, last, negativeCounter = 0;

  for (int i = 0; true; ++i) {
    fseek(F, sizeof(float) * i, 0);
    float * buffer = (float*) malloc (sizeof(float));
    float result = fread (buffer, sizeof(float), 1, F);
    if (*buffer == 0) break;

    if (i == 0) {
      first = *buffer;
    }
    last = *buffer;

    if (*buffer > max || max == NULL) {
      max = *buffer;
    }

    if (*buffer < min || min == NULL) {
      min = *buffer;
      if ((int)min % 2) {
        minOdd = *buffer;
      }
    }

    if (*buffer < 0) {
      negativeCounter++;
    }

    // cout << ftell(F) << ":::" << *buffer << endl;
  }

  cout << endl;
  cout << "First: " << first << endl;
  cout << "Last: " << last << endl;
  cout << "Max: " << max << endl;
  cout << "Min: " << min << endl;
  cout << "Min Odd: " << minOdd << endl;
  cout << "Min + Max: " << min + max << endl;
  cout << "First - Last: " << (first - last) << endl;

  if (negativeCounter > 10) {
    cout << "More than 10 negative nums" << endl;
  }

  return 0;
}
