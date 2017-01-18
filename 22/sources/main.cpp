#include <iostream>
#include <stdio.h>

using namespace std;

int main(void) {

  // Amount of words beginnig with "d" and ending
  // with "w" (the result)
  int unsigned amount = 0;

  // The string we'll work on
  char string[] = "hello,destow,ten,disallow,chairman,bmtsu.";

  int first_char_position;
  char last_char;

  int unsigned length = sizeof(string) / sizeof(*string);

  int unsigned char_num = 0;

  bool found = 0;

  for (int i = 0; i < length; i++, char_num++) {
    /* cout << string[i] << "("; */

    if (string[i] == ',') {
      // Resetting number of char in the word and the flag
      // defined that the word began with seeking char.
      char_num = 0, found = false;

      // Checking that the last char in the last word was another
      // one seeking char.
      if (last_char == 'w') {
        cout << "The addresses of chars of word #" << amount << ":" << endl;
        // The word is found
        for (int j = first_char_position; j < i; j++) {
          printf("  %p", &string[j]);
          cout << endl;
        }
        amount++;
      }
    }

    /* cout << "[" << char_num << "]"; */

    if (string[i] == 'd' && char_num == 1) {
      // The first char of the word is 'h'
      found = true;
      first_char_position = i;
    } else {
      last_char = string[i];
    }

    /* cout << ")" << endl; */

  }

  cout << "Found " << amount << " words begining from 'd' and ending to 'w'" << endl;

  // Getting value by address that user input. This is working code,
  // I commented to for convinient.
  // void* asdasd;
  // cin >> asdasd;
  // cout << *((char*)asdasd);

  return 0;
}
