#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;      // Array to store queue elements
    int front;     // Front points to the front element in the queue
    int rear;      // Rear points to the last element in the queue
    int capacity;  // Maximum size of the queue
    int size;      // Current number of elements in the queue

public:
    
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    
    ~Queue() {
        delete[] arr;
    }

    // Function to add an element at the rear of the queue (enqueue)
    void enqueue(int value) {
        if (size == capacity) {
            cout << "Queue is full! Cannot enqueue " << value << endl;
            return;
        }

        // Circular queue logic
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
        cout << "Enqueued: " << value << endl;
    }

    // Function to remove an element from the front of the queue (dequeue)
    void dequeue() {
        if (size == 0) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }

        cout << "Dequeued: " << arr[front] << endl;

        // Circular queue logic
        front = (front + 1) % capacity;
        size--;
    }

    // Function to get the front element without removing it
    int peek() {
        if (size == 0) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Function to check if the queue is full
    bool isFull() {
        return size == capacity;
    }

    // Function to get the current size of the queue
    int getSize() {
        return size;
    }
};

int main() {
    int capacity;

    
    cout << "Enter the capacity of the queue: ";
    cin >> capacity;

    Queue q(capacity);

    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    
    cout << "Front element: " << q.peek() << endl;

    
    q.dequeue();

   
    if (q.isEmpty()) {
    	
        cout << "The queue is empty!" << endl;
        
    } 
	else {
    	
        cout << "The queue is not empty." << endl;
        
    }

    
    q.enqueue(40);
    q.enqueue(50);

    
    cout << "Queue size: " << q.getSize() << endl;

    return 0;
}

