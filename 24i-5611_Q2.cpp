#include <iostream>
using namespace std;

class Feature {
protected:
    string Name;
public:
    Feature(string n) { Name = n; }
    virtual void analyze() = 0;   
    virtual ~Feature() {}         
};

class LandFeature : public Feature {
public:
    LandFeature(string n) : Feature(n) {}
    void analyze() {
        cout << "Land Feature: " << Name << " detected.\n";
    }
};

class WaterFeature : public Feature {
public:
    WaterFeature(string n) : Feature(n) {}
    void analyze() {
        cout << "Water Feature: " << Name << " detected.\n";
    }
};

struct Node {
    int FeatureID;
    Feature* feature;
    Node* next;
    Node(int id, Feature* f) {
        FeatureID = id;
        feature = f;
        next = NULL;
    }
};

class SinglyLinkedList {
private:
    Node* head;
public:
    SinglyLinkedList() { head = NULL; }

    void insertAtEnd(int featureID, Feature* f) {
        Node* newNode = new Node(featureID, f);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    void deleteByID(int featureID) {
        if (head == NULL)
            return;

        if (head->FeatureID == featureID) {
            Node* del = head;
            head = head->next;
            delete del;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->FeatureID != featureID)
            temp = temp->next;

        if (temp->next == NULL)
            return;

        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }

    void displayAll() {
        Node* temp = head;
        if (temp == NULL) {
            cout << "List is empty.\n";
            return;
        }

        while (temp != NULL) {
            cout << "Feature ID: " << temp->FeatureID << " -> ";
            temp->feature->analyze();
            temp = temp->next;
        }
    }

    void reverseList() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }

    ~SinglyLinkedList() {
        Node* temp = head;
        while (temp != NULL) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    SinglyLinkedList list;

    list.insertAtEnd(1, new LandFeature("Forest"));
    list.insertAtEnd(2, new WaterFeature("River"));
    list.insertAtEnd(3, new LandFeature("Mountain"));
    list.insertAtEnd(4, new WaterFeature("Lake"));

    cout << "Original List:\n";
    list.displayAll();

    cout << "\nDeleting feature with ID 2...\n";
    list.deleteByID(2);
    list.displayAll();

    cout << "\nReversing the list...\n";
    list.reverseList();
    list.displayAll();

    return 0;
}
