#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class Node {
protected:
  void* value;
public:
  Node * next;
  bool isnum = true;
  Node(bool num, void* v) {
    isnum = num;
    value = v;
  }
  void * get() { return value; }
  int getInt() {
  	int value;
    if (isnum) {
    	value = *(int*)(get());
    } else {
    	std::string sv = *(std::string*)(get());
    	value = (int)sv[0];
    }
    return value;
  }
};

class Facade {
protected:
  Node * begin = NULL;
  Node * latest = NULL;
public:

  void add(int v) {
    cout << "# Creating new node for number " << v << endl;
    int * vc = (int*)malloc(sizeof(int));
    *vc = v;
    Node * node = new Node(true, vc);
    if (begin == NULL) {
      begin = node;
    }

    if (latest != NULL)
      latest -> next = node;
    latest = node;
  }
  void add(std::string v) {
    cout << "# Creating new node for number " << v << endl;
    std::string * vc = (std::string*)malloc(sizeof(std::string));
    *vc = v;
    Node * node = new Node(false, vc);
    if (begin == NULL) {
      begin = node;
    }

    if (latest != NULL)
      latest -> next = node;
    latest = node;
  }
  // void remove(int num) {
  //   cout << "# Removing number " << num << endl;
  //   Node * current = latest;
  //   Node * visited = NULL;
  //   while(current != NULL) {
  //     if (!current -> isnum) {
  //       current = current -> next;
  //       continue;
  //     }

  //     int v = *(int*)(current -> get());

  //     if (v == num) {
  //       if (visited)
  //         visited -> next = current -> next;
  //       current = current -> next;
  //       continue;
  //     }

  //     visited = current;
  //     current = current -> next;
  //   }
  // }
  void print() {
    cout << "# Printing" << endl;
    Node * current = begin;
    while(current != NULL) {
      if (current -> isnum) {
        cout << "  " << *(int*)(current -> get()) << endl;
      } else {
        cout << "  " << *(std::string*)(current -> get()) << endl;
      }
      current = current -> next;
    }
  }
};

class SortFacade: public Facade {
	int depth() {
		int count = 0;
		Node * current = begin;
		while(current != NULL) {
			current = current -> next;
			count++;
		}
		return count;
	}
public:
	void sort() {
		cout << "# Sorting" << endl;
    Node * current = begin;
    Node * prev = NULL;
    while(current != NULL) {
    	outer_loop:
    	int value = current -> getInt();

      // cout << value << endl;

      Node * subcurrent = current -> next;
      while(subcurrent != NULL) {
	    	int subvalue = subcurrent -> getInt();

	      // cout << "---- " << subvalue << " (" << value << " > " << subvalue << " )";

	      if (value < subvalue) {
	      	// cout << " --- SWIPE";

	      	//          |------------->
	      	// [prev] [cur] [next]
	      	current -> next = subcurrent -> next;

	      	//          |<----|
	      	// [prev] [cur] [next]
	      	subcurrent -> next = current;

	      	if (prev != NULL){
		      	prev -> next = subcurrent;
	      	} else {
	      		begin = subcurrent;
	      	}

	      	// [prev] [next] [cur]
	      	current = subcurrent;
	      	goto outer_loop;
	      	// prev -> next = subcurrent;
	      	// subcurrent -> next = current;
	      }
      	// cout << endl;
      	subcurrent = subcurrent -> next;
      }
      prev = current;
      current = current -> next;
    }
	}
};



int main(int argc, char* argv[]) {
  SortFacade bfc;
  bfc.add(200);
  bfc.add(300);
  bfc.add("zbc");
  bfc.add(100);

  bfc.sort();
  bfc.print();
  // if (biggest -> isnum) {
  //   cout << "The biggest is number: " << *(int*)bfc.biggest() -> get() << endl;
  // } else {
  //   cout << "The biggest is string: " << *(std::string*)bfc.biggest() -> get() << endl;
  // }
  return 0;
}
