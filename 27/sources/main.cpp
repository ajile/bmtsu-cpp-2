#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Expression {
  string expression;
  public:
    Expression (string);
    string getExpression() {
      return expression;
    };
    int countOperations() {
      int length = expression.size();
      int counter = 0;
      for (int i = 0; i < length; ++i) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '/' || expression[i] == '*') {
          counter++;
        }
      }
      return counter;
    };
};

Expression::Expression(string exp) {
  expression = exp;
}


struct ListNode {
  ListNode* next = NULL;
  Expression* value = NULL;
};


int main(void) {
  Expression * exp1 = new Expression("2+4");
  Expression * exp2 = new Expression("7*10-2");
  Expression * exp3 = new Expression("12-3+1/2");
  Expression * expressions[3] = { exp1, exp2, exp3 };
  /* Expression * expressions = new Expression [3] = (Expression("123+213")); */
  int counter;

  counter = 0;
  for (int i = 0; i < sizeof(expressions) / sizeof(*expressions); ++i){
    string exp = expressions[i] -> getExpression();
    int count = expressions[i] -> countOperations();
    counter += count;
    cout << "Expression '" << exp << "' contains " << count << " operations;" << endl;
  }

  cout << "(array) Total amount of operations is " << counter << endl;




  ListNode *expNode1, *expNode2, *expNode3;

  expNode1 = new ListNode();
  expNode2 = new ListNode();
  expNode3 = new ListNode();
  expNode1 -> value = exp1;
  expNode2 -> value = exp2;
  expNode3 -> value = exp3;
  expNode1 -> next = expNode2;
  expNode2 -> next = expNode3;

  ListNode * expression = expNode1;

  counter = 0;

  do {
    string exp = expression -> value -> getExpression();
    int count = expression -> value -> countOperations();
    counter += count;
    cout << "Expression '" << exp << "' contains " << count << " operations;" << endl;
    expression = expression -> next;
  } while (expression);
  
  cout << "(list) Total amount of operations is " << counter << endl;

  return 0;
}
