#include <iostream>
using namespace std;

struct Node {
    int CustomerID;
    string CustomerName;
    int TicketsRequested;
    Node* next;

    Node(int id, string name, int tickets) {
        CustomerID = id;
        CustomerName = name;
        TicketsRequested = tickets;
        next = NULL;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    void enqueue(int id, string name, int tickets) {
        Node* newNode = new Node(id, name, tickets);

        if (rear == NULL) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty.\n";
            return;
        }

        Node* temp = front;
        cout << "Customer Served: " << temp->CustomerName << endl;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }

    void display() {
        if (front == NULL) {
            cout << "No customers in queue.\n";
            return;
        }

        Node* temp = front;
        cout << "Current Queue:\n";
        while (temp != NULL) {
            cout << "Customer ID: " << temp->CustomerID
                 << ", Name: " << temp->CustomerName
                 << ", Tickets: " << temp->TicketsRequested << endl;
            temp = temp->next;
        }
    }

    ~Queue() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    Queue q;

    q.enqueue(1, "Ali", 2);
    q.enqueue(2, "Sara", 4);
    q.enqueue(3, "Hassan", 1);

    cout << "Initial Queue:\n";
    q.display();

    cout << "\nServing first customer...\n";
    q.dequeue();

    cout << "\nQueue after serving one customer:\n";
    q.display();

    return 0;
}
