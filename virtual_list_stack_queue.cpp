#include <iostream>
#include <stdexcept>
using namespace std;

const int MAX_SIZE = 100;

class List {
public:
    virtual void store(int value) = 0;
    virtual int retrieve() = 0;
    virtual ~List() {}
};

class Stack : public List {
    int arr[MAX_SIZE];
    int top;

public:
    Stack() : top(-1) {}

    void store(int value) override {
        if (top >= MAX_SIZE - 1) {
            throw overflow_error("Stack Overflow");
        }
        arr[++top] = value;
    }

    int retrieve() override {
        if (top < 0) {
            throw underflow_error("Stack Underflow");
        }
        return arr[top--];
    }
};

class Queue : public List {
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue() : front(0), rear(-1) {}

    void store(int value) override {
        if (rear >= MAX_SIZE - 1) {
            throw overflow_error("Queue Overflow");
        }
        arr[++rear] = value;
    }

    int retrieve() override {
        if (front > rear) {
            throw underflow_error("Queue Underflow");
        }
        return arr[front++];
    }
};

int main() {
    List *myStack = new Stack();
    List *myQueue = new Queue();

    try {
        cout << "--- Stack Operations ---" << endl;
        myStack->store(10);
        myStack->store(20);
        myStack->store(30);
        cout << "Stack retrieve: " << myStack->retrieve() << endl;
        cout << "Stack retrieve: " << myStack->retrieve() << endl;

        cout << "\n--- Queue Operations ---" << endl;
        myQueue->store(10);
        myQueue->store(20);
        myQueue->store(30);
        cout << "Queue retrieve: " << myQueue->retrieve() << endl;
        cout << "Queue retrieve: " << myQueue->retrieve() << endl;
    } catch (const exception &e) {
        cout << "Exception: " << e.what() << endl;
    }

    delete myStack;
    delete myQueue;
    return 0;
}
