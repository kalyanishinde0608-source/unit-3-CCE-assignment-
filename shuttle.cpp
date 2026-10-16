#include <iostream>
#include <string>
using namespace std;

struct Node {
    string stop;
    Node* prev;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void addStop(string name) {
    Node* newNode = new Node;
    newNode->stop = name;
    newNode->next = NULL;
    newNode->prev = tail;

    if (head == NULL)
        head = tail = newNode;
    else {
        tail->next = newNode;
        tail = newNode;
    }

    cout << "Stop added successfully!\n";
}

void displayForward() {
    Node* temp = head;

    if (temp == NULL) {
        cout << "No shuttle stops available.\n";
        return;
    }

    cout << "\nCampus Shuttle Route:\n";
    while (temp != NULL) {
        cout << temp->stop;
        if (temp->next != NULL)
            cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

void displayBackward() {
    Node* temp = tail;

    if (temp == NULL) {
        cout << "No shuttle stops available.\n";
        return;
    }

    cout << "\nReverse Shuttle Route:\n";
    while (temp != NULL) {
        cout << temp->stop;
        if (temp->prev != NULL)
            cout << " <-> ";
        temp = temp->prev;
    }
    cout << endl;
}

void searchStop(string name) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->stop == name) {
            cout << "Stop found: " << name << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Stop not found.\n";
}

void deleteStop(string name) {
    Node* temp = head;

    while (temp != NULL && temp->stop != name)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Stop not found.\n";
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev;

    delete temp;
    cout << "Stop deleted successfully!\n";
}

int main() {
    int choice;
    string name;

    do {
        cout << "\n===== CAMPUS SHUTTLE MANAGEMENT =====\n";
        cout << "1. Add Shuttle Stop\n";
        cout << "2. Display Route Forward\n";
        cout << "3. Display Route Backward\n";
        cout << "4. Search Shuttle Stop\n";
        cout << "5. Delete Shuttle Stop\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter stop name: ";
            getline(cin >> ws, name);
            addStop(name);
            break;

        case 2:
            displayForward();
            break;

        case 3:
            displayBackward();
            break;

        case 4:
            cout << "Enter stop name to search: ";
            getline(cin >> ws, name);
            searchStop(name);
            break;

        case 5:
            cout << "Enter stop name to delete: ";
            getline(cin >> ws, name);
            deleteStop(name);
            break;

        case 6:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    // Free all remaining nodes
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = NULL;

    return 0;
}
