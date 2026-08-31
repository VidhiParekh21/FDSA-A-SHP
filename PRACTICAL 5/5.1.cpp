#include <iostream>
#include <string>
using namespace std;
struct Node {
    string song;
    Node *prev, *next;
};
Node* head = NULL;
Node* tail = NULL;
void addBeginning() {
    string song;
    cout << "Enter song name: ";
    cin >> song;
    Node* n = new Node;
    n->song = song;
    n->prev = NULL;
    n->next = head;
    if (head != NULL)
        head->prev = n;
    else
        tail = n;
    head = n;
}
void addEnd() {
    string song;
    cout << "Enter song name: ";
    cin >> song;
    Node* n = new Node;
    n->song = song;
    n->next = NULL;
    n->prev = tail;
    if (tail != NULL)
        tail->next = n;
    else
        head = n;
    tail = n;
}
void insertAfter() {
    string oldSong, newSong;
    cout << "Enter song after which to insert: ";
    cin >> oldSong;
    cout << "Enter new song name: ";
    cin >> newSong;
    Node* temp = head;
    while (temp != NULL && temp->song != oldSong)
        temp = temp->next;
    if (temp == NULL) {
        cout << "Song not found!\n";
        return;
    }
    Node* n = new Node;
    n->song = newSong;
    n->next = temp->next;
    n->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = n;
    else
        tail = n;
    temp->next = n;
}
void removeFirst() {
    if (head == NULL) {
        cout << "Playlist is empty!\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL;
    delete temp;
    cout << "First song removed.\n";
}
void countSongs() {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    cout << "Total songs: " << count << endl;
}
void display() {
    if (head == NULL) {
        cout << "Playlist is empty!\n";
        return;
    }
    Node* temp = head;
    cout << "Playlist: ";
    while (temp != NULL) {
        cout << temp->song << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    int choice;
    do {
        cout << "\n1. Add at beginning\n";
        cout << "2. Add at end\n";
        cout << "3. Insert after song\n";
        cout << "4. Remove first song\n";
        cout << "5. Count songs\n";
        cout << "6. Display playlist\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addBeginning();
                display();
                break;
            case 2:
                addEnd();
                display();
                break;
            case 3:
                insertAfter();
                display();
                break;
            case 4:
                removeFirst();
                display();
                break;
            case 5:
                countSongs();
                break;
            case 6:
                display();
                break;
            case 7:
                cout << "Program ended.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 7);
    return 0;
}
