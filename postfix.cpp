#include <iostream>
#include <stack>
#include <string>
#include <cctype> // For isdigit()

using namespace std;

// Function to evaluate a postfix expression
int evaluatePostfix(const string& expression) {
    stack<int> s;

    // Traverse the expression character by character
    for (size_t i = 0; i < expression.length(); ++i) {
        char ch = expression[i];

        if (isdigit(ch)) {
            // If the character is a digit, push it onto the stack
            s.push(ch - '0'); // Convert char to integer
        } else {
            // If the character is an operator, pop two operands from the stack
            if (s.size() < 2) {
                cerr << "Error: Invalid postfix expression!" << endl;
                return -1;
            }
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();

            // Perform the operation and push the result back onto the stack
            switch (ch) {
                case '+':
                    s.push(operand1 + operand2);
                    break;
                case '-':
                    s.push(operand1 - operand2);
                    break;
                case '*':
                    s.push(operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        cerr << "Error: Division by zero!" << endl;
                        return -1;
                    }
                    s.push(operand1 / operand2);
                    break;
                default:
                    cerr << "Error: Invalid operator " << ch << endl;
                    return -1;
            }
        }
    }

    // The final result should be at the top of the stack
    if (s.size() != 1) {
        cerr << "Error: Invalid postfix expression!" << endl;
        return -1;
    }

    return s.top();
}

int main() {
    string postfixExpression = "23*54**9-";
    int result = evaluatePostfix(postfixExpression);

    if (result != -1) {
        cout << "The result of the postfix expression " << postfixExpression << " is: " << result << endl;
    }

    return 0;
}

