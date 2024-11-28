#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) {
        return n; // Base case: fibonacci(0) = 0, fibonacci(1) = 1
    }
    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
}

int main() {
    int terms;

    cout << "Enter the number of terms for Fibonacci series: ";
    cin >> terms;

    cout << "Fibonacci Series: ";
    for (int i = 1; i <=terms; ++i) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;

    return 0;
}

