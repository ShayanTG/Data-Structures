#include <iostream>
using namespace std;

class ArrayQueue {
private:
    int front, rear, size, capacity;
    int* arr;

public:
    ArrayQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    void enqueue(int obj) {
        if (isFull()) {
            cout << "full!" << endl;
            return;
        }
        arr[++rear] = obj;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "empty!" << endl;
            return -1;
        }
        int obj = arr[front];
        for (int i = 0; i < rear; i++) {
            arr[i] = arr[i + 1];
        }
        rear--;
        size--;
        return obj;
    }

    int peek() {
        if (isEmpty()) {
            cout << "empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    void reverseQueue() {
        int start = front, end = rear;
        while (start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    ~ArrayQueue() {
        delete[] arr;
    }
};

class CircularQueue {
private:
    int front, rear, size, capacity;
    int* arr;

public:
    CircularQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    void enqueue(int obj) {
        if (isFull()) {
            cout << "full!" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = obj;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "empty!" << endl;
            return -1;
        }
        int obj = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        size--;
        return obj;
    }

    int peek() {
        if (isEmpty()) {
            cout << "empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    void reverseQueue() {
        if (isEmpty()) return;

        int temp[capacity];
        int i = 0;
        int index = front;
        do {
            temp[i++] = arr[index];
            index = (index + 1) % capacity;
        } while (index != (rear + 1) % capacity);

        for (int j = 0; j < size; j++) {
            arr[(rear - j + capacity) % capacity] = temp[j];
        }
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    ArrayQueue aq(10);
    CircularQueue cq(5);

    string method;
    while (true) {
        cout << "\nEnter the method (aEnqueue, aDequeue, aPeek, cEnqueue, cDequeue, cPeek, exit): ";
        cin >> method;

        int value;
        if (method == "aEnqueue") {
            cout << "Enter the value: ";
            cin >> value;
            aq.enqueue(value);
        } else if (method == "aDequeue") {
            int result = aq.dequeue();
            if (result != -1) cout << "Dequeued: " << result << endl;
        } else if (method == "aPeek") {
            int result = aq.peek();
            if (result != -1) cout << "Peek: " << result << endl;
        } else if (method == "cEnqueue") {
            cout << "Enter the value: ";
            cin >> value;
            cq.enqueue(value);
        } else if (method == "cDequeue") {
            int result = cq.dequeue();
            if (result != -1) cout << "Dequeued: " << result << endl;
        } else if (method == "cPeek") {
            int result = cq.peek();
            if (result != -1) cout << "Peek: " << result << endl;
        } else if (method == "exit") {
            cout << "Operation done.\n";
            break;
        } else {
            cout << "Invalid method" << endl;
        }
    }

    return 0;
}
