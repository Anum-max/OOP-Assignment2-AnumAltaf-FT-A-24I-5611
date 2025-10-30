#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node(char val) {
        data = val;
        next = NULL;
    }
};

class LinkedListStack {
private:
    Node* top;
public:
    LinkedListStack() { top = NULL; }

    void push(char val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    char peek() {
        if (top != NULL)
            return top->data;
        return '\0';
    }

    bool isEmpty() {
        return top == NULL;
    }

    ~LinkedListStack() {
        while (!isEmpty())
            pop();
    }
};
class ArrayStack {
private:
    int top;
    char arr[100];
public:
    ArrayStack() { top = -1; }

    void push(char val) {
        if (top < 99)
            arr[++top] = val;
    }

    void pop() {
        if (top >= 0)
            top--;
    }

    char peek() {
        if (top >= 0)
            return arr[top];
        return '\0';
    }

    bool isEmpty() {
        return top == -1;
    }
};
void ChangeLocation_Iterative(char *Array, int b1, int b2) {
    LinkedListStack s;

    for (int i = b1; i <= b2; i++)
        s.push(Array[i]);

    for (int i = b1; i <= b2; i++) {
        Array[i] = s.peek();
        s.pop();
    }

    cout << "Array after swapping: ";
    for (int i = 0; i < 8; i++)
        cout << Array[i] << " ";
    cout << endl;
}
void PrintPattern_Iterative(int n) {
    ArrayStack s;

    for (int i = n; i >= 1; i--)
        s.push(i);

    cout << "Pattern:\n";
    while (!s.isEmpty()) {
        int x = s.peek() - '0';  
        s.pop();

        for (int j = 0; j < x; j++)
            cout << x << " ";
        cout << endl;
    }
}
int main() {
    char Array[8] = {'C', 'O', 'M', 'P', 'U', 'T', 'E', 'R'};

    cout << "Original Array: ";
    for (int i = 0; i < 8; i++)
        cout << Array[i] << " ";
    cout << endl;

    ChangeLocation_Iterative(Array, 2, 6); 
    int n = 4;
    PrintPattern_Iterative(n);

    return 0;
}
