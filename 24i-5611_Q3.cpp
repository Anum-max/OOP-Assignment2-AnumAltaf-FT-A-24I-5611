#include <iostream>
using namespace std;

struct Node {
    int BookID;
    string Title;
    string Author;
    Node* next;
    Node* prev;

    Node(int id, string t, string a) {
        BookID = id;
        Title = t;
        Author = a;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList() { head = NULL; }

    void addAtBeginning(int id, string title, string author) {
        Node* newNode = new Node(id, title, author);
        if (head == NULL) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void addAtEnd(int id, string title, string author) {
        Node* newNode = new Node(id, title, author);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void addAtPosition(int pos, int id, string title, string author) {
        if (pos <= 1) {
            addAtBeginning(id, title, author);
            return;
        }

        Node* temp = head;
        int count = 1;
        while (temp != NULL && count < pos - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == NULL) { 
            addAtEnd(id, title, author);
            return;
        }

        Node* newNode = new Node(id, title, author);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
            temp->next->prev = newNode;

        temp->next = newNode;
    }

    void deleteByID(int id) {
        if (head == NULL)
            return;

        Node* temp = head;

        if (head->BookID == id) {
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            delete temp;
            return;
        }

        while (temp != NULL && temp->BookID != id)
            temp = temp->next;

        if (temp == NULL)
            return;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        if (temp->prev != NULL)
            temp->prev->next = temp->next;

        delete temp;
    }

    void displayForward() {
        if (head == NULL) {
            cout << "Library is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Books in order:\n";
        while (temp != NULL) {
            cout << "Book ID: " << temp->BookID
                 << ", Title: " << temp->Title
                 << ", Author: " << temp->Author << endl;
            temp = temp->next;
        }
    }

    void displayBackward() {
        if (head == NULL) {
            cout << "Library is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        cout << "Books in reverse order:\n";
        while (temp != NULL) {
            cout << "Book ID: " << temp->BookID
                 << ", Title: " << temp->Title
                 << ", Author: " << temp->Author << endl;
            temp = temp->prev;
        }
    }

    ~DoublyLinkedList() {
        Node* temp = head;
        while (temp != NULL) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    DoublyLinkedList library;

    library.addAtEnd(1, "C++ Programming", "Bjarne Stroustrup");
    library.addAtEnd(2, "Data Structures", "Mark Weiss");
    library.addAtBeginning(3, "Algorithms", "Robert Sedgewick");
    library.addAtPosition(2, 4, "OOP Concepts", "Grady Booch");

    cout << "After adding books:\n";
    library.displayForward();

    cout << "\nDeleting book with ID 2...\n";
    library.deleteByID(2);
    library.displayForward();

    cout << "\nDisplaying books in reverse order:\n";
    library.displayBackward();

    return 0;
}
