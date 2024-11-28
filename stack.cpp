#include <iostream>
#include <stack>
using namespace std;

// Stack class using std::stack
class Stack {
private:
    stack<int> myStack;

public:
    // Function to check if the stack is empty
    bool isEmpty() {
        return myStack.empty();
    }

    // Function to push a value onto the stack
    void push(int value) {
        myStack.push(value);
        cout << "Pushed: " << value << endl;
    }

    // Function to pop a value from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }

        cout << "Popped: " << myStack.top() << endl;
        myStack.pop();
    }

    // Function to get the top element of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot peek." << endl;
            return -1; // Assuming -1 is an invalid value
        }

        return myStack.top();
    }

    // Function to display the elements of the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack elements: ";
        stack<int> tempStack = myStack;
        while (!tempStack.empty()) {
            cout << tempStack.top() << " ";
            tempStack.pop();
        }
        cout << endl;
    }
};

int main() {
    // Creating a stack object
    Stack myStack;

    // Pushing elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Displaying the top element
    cout << "Top element: " << myStack.peek() << endl;

    // Popping an element
    myStack.pop();

    // Displaying the elements
    myStack.display();

    return 0;
}

