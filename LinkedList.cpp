#include <iostream>
using namespace std;

class LinkedList {
private:
    struct Node {
        int data;     
        Node* next;  
    };
    Node* head;     
    int size;        

public:
    LinkedList() : head(nullptr), size(0) {}

    void insertAtIndex(int data, int index) {
        if (index < 0 || index > size) return; 

        Node* newNode = new Node{data, nullptr}; 
        if (index == 0) {
            newNode->next = head; 
            head = newNode;   
        } else {
            Node* temp = head; 
            for (int i = 0; i < index - 1; i++) temp = temp->next; 
            newNode->next = temp->next; 
            temp->next = newNode;      
        }
        size++;
    }

    void insertAtEnd(int data) {
        insertAtIndex(data, size); 
    }

    void insertAtBegin(int data) {
        insertAtIndex(data, 0);
    }

    void updateNode(int data, int index) {
        if (index < 0 || index >= size) return; 

        Node* temp = head;
        for (int i = 0; i < index; i++) temp = temp->next; 
        temp->data = data;
    }

    int removeNodeAtIndex(int index) {
        if (index < 0 || index >= size) return -1;

        Node* temp = head;
        int data;
        if (index == 0) { 
            data = head->data; 
            head = head->next; 
            delete temp;     
        } else {
            for (int i = 0; i < index - 1; i++) temp = temp->next;
            Node* toDelete = temp->next; 
            data = toDelete->data;      
            temp->next = toDelete->next; 
            delete toDelete;          
        }
        size--; 
        return data; 
    }

    int removeNodeAtEnd() {
        return removeNodeAtIndex(size - 1); 
    }

    int removeNodeAtBegin() {
        return removeNodeAtIndex(0); 
    }

    int sizeOfList() {
        return size;
    }

    void concatenate(LinkedList& other) {
        Node* temp = head;
        if (!temp) {
            head = other.head;
        } else {
            while (temp->next) temp = temp->next;
            temp->next = other.head;
        }
        size += other.size; 
        other.head = nullptr;
        other.size = 0;
    }

    void invert() {
        Node* prev = nullptr; 
        Node* curr = head;   
        Node* next = nullptr; 
        while (curr) {
            next = curr->next; 
            curr->next = prev; 
            prev = curr;      
            curr = next;      
        }
        head = prev; 
    }

    void printList() {
        Node* temp = head; 
        while (temp != nullptr) { 
            cout << temp->data << " -> ";
            temp = temp->next; 
        }
        cout << "NULL" << endl; 
    }

    
};


class CircularLinkedList {
private:
    struct Node {
        int data;     
        Node* next;   
    };
    Node* tail;      
    int size;       

public:
    CircularLinkedList() : tail(nullptr), size(0) {}

    void insertAtIndex(int data, int index) {
        if (index < 0 || index > size) return; 

        Node* newNode = new Node{data, nullptr}; 
        if (size == 0) { 
            newNode->next = newNode; 
            tail = newNode;       
        } else if (index == 0) { 
            newNode->next = tail->next; 
            tail->next = newNode;    
        } else {
            Node* temp = tail->next; 
            for (int i = 0; i < index - 1; i++) temp = temp->next; 
            newNode->next = temp->next; 
            temp->next = newNode;    
            if (index == size) tail = newNode; 
        }
        size++; 
    }

    void insertAtEnd(int data) {
        insertAtIndex(data, size); 
    }

    void insertAtBegin(int data) {
        insertAtIndex(data, 0); 
    }

    void updateNode(int data, int index) {
        if (index < 0 || index >= size) return; 

        Node* temp = tail->next; 
        for (int i = 0; i < index; i++) temp = temp->next; 
        temp->data = data; 
    }

    int removeNodeAtIndex(int index) {
        if (index < 0 || index >= size) return -1; 

        Node* temp = tail->next; 
        int data;
        if (size == 1) { 
            data = temp->data; 
            delete temp;      
            tail = nullptr;   
        } else if (index == 0) { 
            Node* toDelete = tail->next;
            data = toDelete->data;
            tail->next = toDelete->next; 
            delete toDelete;
        } else {
            for (int i = 0; i < index - 1; i++) temp = temp->next; 
            Node* toDelete = temp->next; 
            data = toDelete->data;
            temp->next = toDelete->next; 
            if (index == size - 1) tail = temp; 
            delete toDelete;
        }
        size--; 
        return data; 
    }

    int removeNodeAtEnd() {
        return removeNodeAtIndex(size - 1);
    }

    int removeNodeAtBegin() {
        return removeNodeAtIndex(0);
    }

    int sizeOfList() {
        return size;
    }

    void concatenate(CircularLinkedList& other) {
        if (!tail) { 
            tail = other.tail;
        } else if (other.tail) { 
            Node* temp = tail->next; 
            tail->next = other.tail->next; 
            other.tail->next = temp; 
            tail = other.tail; 
        }
        size += other.size; 
        other.tail = nullptr; 
        other.size = 0;
    }

    void invert() {
        if (!tail || size == 1) return; 

        Node* prev = nullptr;
        Node* curr = tail->next; 
        Node* next = nullptr;
        Node* head = tail->next; 

        do {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        } while (curr != head);

        tail->next = prev; 
        tail = head; 
    }

    void printList() {
        if (!tail) {
            cout << "list empty" << endl;
            return;
        }
        Node* temp = tail->next; 
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next); 
        cout << "(loop)" << endl;
    }
};


class DoublyLinkedList {
private:
    struct Node {
        int data;      
        Node* prev;    
        Node* next;    
    };
    Node* head;        
    Node* tail;       
    int size;         

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void insertAtIndex(int data, int index) {
        if (index < 0 || index > size) return; 

        Node* newNode = new Node{data, nullptr, nullptr}; 
        if (size == 0) { 
            head = tail = newNode; 
        } else if (index == 0) { 
            newNode->next = head; 
            head->prev = newNode;
            head = newNode;       
        } else if (index == size) { 
            newNode->prev = tail; 
            tail->next = newNode;
            tail = newNode;      
        } else { 
            Node* temp = head; 
            for (int i = 0; i < index - 1; i++) temp = temp->next; 
            newNode->next = temp->next; 
            newNode->prev = temp;     
            temp->next->prev = newNode;
            temp->next = newNode;
        }
        size++; 
    }

    void insertAtEnd(int data) {
        insertAtIndex(data, size); 
    }

    void insertAtBegin(int data) {
        insertAtIndex(data, 0); 
    }

    void updateNode(int data, int index) {
        if (index < 0 || index >= size) return; 

        Node* temp = head; 
        for (int i = 0; i < index; i++) temp = temp->next; 
        temp->data = data; 
    }

    int removeNodeAtIndex(int index) {
        if (index < 0 || index >= size) return -1; 

        Node* toDelete = head; 
        int data;
        if (size == 1) { 
            data = head->data;
            delete head; 
            head = tail = nullptr;
        } else if (index == 0) { 
            toDelete = head;
            data = toDelete->data;
            head = head->next; 
            head->prev = nullptr;
            delete toDelete;
        } else if (index == size - 1) { 
            toDelete = tail;
            data = toDelete->data;
            tail = tail->prev; 
            tail->next = nullptr;
            delete toDelete;
        } else { 
            for (int i = 0; i < index; i++) toDelete = toDelete->next; 
            data = toDelete->data;
            toDelete->prev->next = toDelete->next; 
            toDelete->next->prev = toDelete->prev;
            delete toDelete;
        }
        size--; 
        return data; 
    }

    int removeNodeAtEnd() {
        return removeNodeAtIndex(size - 1);
    }

    int removeNodeAtBegin() {
        return removeNodeAtIndex(0);
    }

    int sizeOfList() {
        return size;
    }

    void concatenate(DoublyLinkedList& other) {
        if (!head) { 
            head = other.head;
            tail = other.tail;
        } else if (other.head) { 
            tail->next = other.head; 
            other.head->prev = tail;
            tail = other.tail; 
        }
        size += other.size; 
        other.head = other.tail = nullptr; 
        other.size = 0;
    }

    void invert() {
        if (!head || size == 1) return; 

        Node* current = head;
        Node* temp = nullptr;

        while (current) {
            temp = current->prev;      
            current->prev = current->next;
            current->next = temp;
            current = current->prev;    
        }

        temp = head; 
        head = tail;
        tail = temp;
    }

    void printList() {
        if (!head) {
            cout << "empty list" << endl;
            return;
        }
        Node* temp = head; 
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

class Array {
private:
    LinkedList list;

public:
    void pushBack(int data) {
        list.insertAtEnd(data);
    }

    void updateAtIndex(int index, int data) {
        list.updateNode(data, index);
    }

    int removeAtIndex(int index) {
        return list.removeNodeAtIndex(index);
    }

    int size() {
        return list.sizeOfList();
    }

    void printArray() {
        list.printList();
    }
};



class Stack {
private:
    LinkedList list;

public:
    void push(int data) {
        list.insertAtBegin(data);
    }

    int pop() {
        return list.removeNodeAtBegin();
    }

    int top() {
        if (list.sizeOfList() > 0) {
            return list.removeNodeAtBegin();
        }
        return -1; 
    }

    int size() {
        return list.sizeOfList();
    }

    void printStack() {
        list.printList();
    }
};

class Queue {
private:
    LinkedList list;

public:
    void enqueue(int data) {
        list.insertAtEnd(data);
    }

    int dequeue() {
        return list.removeNodeAtBegin();
    }

    int front() {
        if (list.sizeOfList() > 0) {
            return list.removeNodeAtBegin(); 
        }
        return -1; 
    }

    int size() {
        return list.sizeOfList();
    }

    void printQueue() {
        list.printList();
    }
};
