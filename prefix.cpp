#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to evaluate a prefix expression
int evaluatePrefix(const string& expression) {
    stack<int> s;  // Stack to store operands

    // Traverse the expression from right to left
    for (int i = expression.length() - 1; i >= 0; i--) {
        char ch = expression[i];

        // If the character is a digit, push it onto the stack
        if (isdigit(ch)) {
            s.push(ch - '0');
        }
        // If the character is an operator, pop two operands and perform the operation
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int operand1 = s.top();
            s.pop();
            int operand2 = s.top();
            s.pop();

            int result;
            if (ch == '+') {
                result = operand1 + operand2;
            } else if (ch == '-') {
                result = operand1 - operand2;
            } else if (ch == '*') {
                result = operand1 * operand2;
            } else if (ch == '/') {
                result = operand1 / operand2;
            }

            // Push the result back onto the stack
            s.push(result);
        }
    }

    // The final result will be the only item left in the stack
    return s.top();
}

int main() {
    string prefixExpression;

    // Get the prefix expression from the user
    cout << "Enter a prefix expression: ";
    cin >> prefixExpression;

    // Evaluate the prefix expression
    int result = evaluatePrefix(prefixExpression);

    // Output the result
    cout << "The result of the prefix expression is: " << result << endl;

    return 0;
}

