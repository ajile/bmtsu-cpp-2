#include <iostream>
#include <stdio.h>

// Contains malloc function
#include <cstdlib>
#include <string.h>

using namespace std;

struct Node {
  char* value;
  Node* prev;
};

int main(void) {

  // The origin string that user supposed to input
  // char words[] = "the list of the word in accordance with exercise";

  char words[80];
  cout << "Input a string: ";
  cin.getline(words, 80);

  // Where current word in the string starts and ends
  int unsigned start = 0, end = 0;

  // Length of the string
  int unsigned length = strlen(words);

  Node* pointer = NULL;
  Node* prev = NULL;

  cout << "The origin string: " << words << endl;

  // Iterating over all chars in the string
  for (int i = 0; i < length; ++i) {

    // At the end of the word
    if (words[i] == ' ' || i == length - 1) {

      // Giving to "i" a name for convinience
      end = i;

      unsigned int word_length = end - start;

      // cout << "((s:" << start << "; e:" << end << "))" << word_length;

      // Getting a memory for storing the word
      char *word = (char *)malloc(sizeof(char) * (word_length + 1));

      //========================== The word scope here begins

      // cout << "[";

      // Iterating over the word
      for (int j = start, pos = 0; j < end; ++j, ++pos) {
        // cout << words[j];
        word[pos] = words[j];
      }
      word[word_length] = '\0';

      // cout << "]";

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

  // cout << endl;
  cout << endl;
  cout << "# Printing words by interating over the stack:" << endl;

  int amount = 0;

  Node *top = pointer;

  // just printing the list
  while (pointer) {
    cout << "    " << (pointer -> value) << endl;
    strlen(pointer -> value) < 3 && ++amount;
    pointer = pointer -> prev;
  }

  cout << "# Amount of words which length less three: " << amount << endl;

  cout << "Input length of the words (N): ";

  int amount_to_delete;

  cin >> amount_to_delete;

  pointer = top;

  Node* visited = NULL;

  // just printing the list
  while (pointer) {
    // cout << strlen(pointer -> value) << ":" << amount_to_delete << endl;
    if (strlen(pointer -> value) <= amount_to_delete) {
      if (visited != NULL) {
        // Changing pointer from previous element in stack
        // cout << endl << "[[[" << (visited -> prev -> value) << "]]]" << endl;
        visited -> prev = pointer -> prev;
      }
      pointer = pointer -> prev;
      continue;
    }
    // cout << "    " << (pointer -> value) << endl;
    visited = pointer;
    pointer = pointer -> prev;
  }

  cout << "# Words less then N length: " << endl;

  pointer = top;

  while (pointer) {
    cout << "    " << (pointer -> value) << endl;
    strlen(pointer -> value) < 3 && ++amount;
    pointer = pointer -> prev;
  }


  return 0;
}
