#include <iostream>
#include <stdio.h>

using namespace std;

struct Node {
  char* value;
  Node* prev;
};

void foo(char* words) {
  cout << strlen(words);
}

int main(void) {

  // The origin string that user supposed to input
  char words[] = "the list of the word in accordance with exercise";

  foo(words);

  // Where current word in the string starts and ends
  int unsigned start = 0, end = 0;

  // Length of the string
  int unsigned length = sizeof(words) / sizeof(*words);

  Node* pointer = NULL;
  Node* prev = NULL;

  cout << "The origin string: " << words << endl;

  // Iterating over all chars in the string
  for (int i = 0; i < length; ++i) {

    // At the end of the word
    if (words[i] == ' ' || i == length - 1) {

      // Giving to "i" a name for convinience
      end = i;

      int unsigned word_length = end - start;

      char *word = (char *)malloc(sizeof(char) * (word_length + 1));

      //========================== The word scope here begins

      cout << "[";

      // Iterating over the word
      for (int j = start, pos = 0; j < end; ++j, ++pos) {
        cout << words[j];
        word[pos] = words[j];
      }
      word[word_length] = '\0';

      cout << "]";

      // Creating a new Node of the stack putting value and pointing
      // to previous Node if it's exist.
      pointer = new Node();
      pointer -> value = word;
      pointer -> prev = prev;

      prev = pointer;

      //========================== The word scope here ends

      start = i + 1;
    }

  }

  cout << endl;
  cout << endl;

  // Just printing the list
  while (pointer) {
    cout << (pointer -> value) << endl;
    pointer = pointer -> prev;
  }

  return 0;
}
